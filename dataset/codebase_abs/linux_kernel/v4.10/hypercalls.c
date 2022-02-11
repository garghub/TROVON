static void F_1 ( struct V_1 * V_2 , struct V_3 * args )
{
switch ( args -> V_4 ) {
case V_5 :
break;
case V_6 :
break;
case V_7 :
F_2 ( V_2 , L_1 ) ;
break;
case V_8 : {
char V_9 [ 128 ] ;
F_3 ( V_2 , V_9 , args -> V_10 , sizeof( V_9 ) ) ;
V_9 [ sizeof( V_9 ) - 1 ] = '\0' ;
F_2 ( V_2 , L_2 , V_9 ) ;
if ( args -> V_11 == V_12 )
V_2 -> V_13 -> V_14 = F_4 ( - V_15 ) ;
break;
}
case V_16 :
if ( args -> V_10 )
F_5 ( V_2 ) ;
else
F_6 ( V_2 ) ;
break;
case V_17 :
F_7 ( V_2 , args -> V_10 ) ;
break;
case V_18 :
F_8 ( V_2 , args -> V_10 , args -> V_11 , args -> V_19 ) ;
break;
case V_20 :
#ifdef F_9
F_10 ( V_2 , args -> V_10 , args -> V_11 ,
F_11 ( args -> V_19 | ( V_21 ) args -> V_22 << 32 ) ) ;
#else
F_10 ( V_2 , args -> V_10 , args -> V_11 , F_11 ( args -> V_19 ) ) ;
#endif
break;
case V_23 :
F_12 ( V_2 -> V_13 , args -> V_10 , args -> V_11 ) ;
break;
#ifdef F_9
case V_24 :
F_13 ( V_2 -> V_13 , args -> V_10 , args -> V_11 ) ;
break;
#endif
case V_25 :
F_14 ( V_2 , args -> V_10 ) ;
break;
case V_26 :
V_2 -> V_27 = 1 ;
break;
default:
if ( F_15 ( V_2 , args ) )
F_2 ( V_2 , L_3 , args -> V_4 ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
unsigned int V_28 ;
T_1 V_29 [ V_30 ] ;
if ( F_17 ( & V_29 , & V_2 -> V_13 -> V_31 -> V_32 , sizeof( V_29 ) ) )
return;
for ( V_28 = 0 ; V_28 < F_18 ( V_29 ) ; V_28 ++ ) {
struct V_3 args ;
unsigned int V_33 = V_2 -> V_34 ;
if ( V_29 [ V_33 ] == 0xFF )
break;
if ( ++ V_2 -> V_34 == V_30 )
V_2 -> V_34 = 0 ;
if ( F_17 ( & args , & V_2 -> V_13 -> V_31 -> V_35 [ V_33 ] ,
sizeof( struct V_3 ) ) ) {
F_2 ( V_2 , L_4 ) ;
break;
}
F_1 ( V_2 , & args ) ;
if ( F_19 ( 0xFF , & V_2 -> V_13 -> V_31 -> V_32 [ V_33 ] ) ) {
F_2 ( V_2 , L_5 ) ;
break;
}
if ( V_2 -> V_36 . V_37 )
break;
}
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 -> V_4 != V_7 ) {
F_2 ( V_2 , L_6 , V_2 -> V_38 -> V_4 ) ;
return;
}
if ( F_21 ( V_2 ) )
F_2 ( V_2 , L_7 , V_2 -> V_13 -> V_31 ) ;
if ( F_22 ( V_2 -> V_13 -> V_39 , & V_2 -> V_13 -> V_31 -> V_39 ) )
F_2 ( V_2 , L_7 , V_2 -> V_13 -> V_31 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
F_5 ( V_2 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
if ( F_26 ( ! V_2 -> V_13 -> V_31 ) ) {
F_20 ( V_2 ) ;
V_2 -> V_38 = NULL ;
return;
}
F_16 ( V_2 ) ;
if ( ! V_2 -> V_36 . V_37 ) {
F_1 ( V_2 , V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
}
}
void F_23 ( struct V_1 * V_2 )
{
struct V_40 V_41 ;
F_27 ( & V_41 ) ;
if ( F_28 ( & V_2 -> V_13 -> V_31 -> time ,
& V_41 , sizeof( struct V_40 ) ) )
F_2 ( V_2 , L_8 ) ;
}
