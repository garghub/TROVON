static void T_1 * T_2 F_1 ( unsigned long V_1 , T_3 V_2 )
{
void T_1 * V_3 ;
#ifdef F_2
F_3 ( V_4 , V_1 & V_5 ) ;
V_3 = ( void T_1 * ) F_4 ( V_4 ) ;
V_3 += V_1 & ~ V_5 ;
#else
V_3 = F_5 ( V_1 , V_2 ) ;
#endif
if ( ! V_3 )
F_6 ( L_1 , V_6 ,
( unsigned long long ) V_1 ) ;
return V_3 ;
}
static int T_2 F_7 ( struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = & V_8 -> V_11 ;
int V_12 ;
unsigned long V_13 ;
if ( F_8 ( V_9 , & V_11 -> V_14 , & V_13 , & V_9 ) )
return - V_15 ;
switch ( V_11 -> V_14 ) {
case V_16 :
case V_17 :
V_11 -> V_18 = 2 ;
case V_19 :
V_11 -> V_20 = V_13 ;
break;
case V_21 :
V_11 -> V_22 = V_13 ;
break;
default:
return - V_15 ;
}
if ( V_9 ) {
V_8 -> V_23 = F_9 ( V_9 , NULL , 0 ) ;
V_12 = F_10 ( strcspn ( V_9 , L_2 ) + 1 ,
( T_3 ) ( sizeof( V_8 -> V_9 ) ) ) ;
F_11 ( V_8 -> V_9 , V_9 , V_12 ) ;
}
if ( V_11 -> V_14 == V_19 || V_11 -> V_14 == V_16 ||
V_11 -> V_14 == V_17 )
F_12 ( L_3 ,
( V_11 -> V_14 == V_19 ) ? L_4 :
( V_11 -> V_14 == V_16 ) ? L_5 : L_6 ,
( unsigned long long ) V_11 -> V_20 ,
V_8 -> V_9 ) ;
else
F_12 ( L_7 ,
V_11 -> V_22 ,
V_8 -> V_9 ) ;
return 0 ;
}
static int T_2 F_13 ( char * V_24 , const struct V_25 * V_26 )
{
int V_27 ;
struct V_10 * V_11 = & V_28 . V_11 ;
if ( V_24 && ! F_7 ( & V_28 , V_24 ) )
V_24 = NULL ;
F_14 ( & V_11 -> V_29 ) ;
V_11 -> V_30 = V_31 * 16 ;
if ( V_11 -> V_20 )
V_11 -> V_32 = F_1 ( V_11 -> V_20 , 64 ) ;
V_28 . V_33 -> V_34 = & V_28 ;
V_27 = V_26 -> V_35 ( & V_28 , V_24 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( ! V_28 . V_33 -> V_36 )
return - V_37 ;
F_15 ( V_28 . V_33 ) ;
return 0 ;
}
int T_2 F_16 ( char * V_24 )
{
const struct V_25 * V_26 ;
if ( ! V_24 || ! V_24 [ 0 ] )
return - V_15 ;
if ( V_38 . V_39 & V_40 )
return - V_41 ;
for ( V_26 = V_42 ; V_26 -> V_43 [ 0 ] ; V_26 ++ ) {
T_3 V_44 = strlen ( V_26 -> V_43 ) ;
if ( strncmp ( V_24 , V_26 -> V_43 , V_44 ) )
continue;
if ( V_24 [ V_44 ] ) {
if ( V_24 [ V_44 ] != ',' )
continue;
V_24 += V_44 + 1 ;
} else
V_24 = NULL ;
return F_13 ( V_24 , V_26 ) ;
}
return - V_45 ;
}
static int T_2 F_17 ( char * V_24 )
{
int V_27 ;
if ( ! V_24 || ! V_24 [ 0 ] )
return 0 ;
V_27 = F_16 ( V_24 ) ;
if ( V_27 == - V_45 || V_27 == - V_41 )
return 0 ;
return V_27 ;
}
int T_2 F_18 ( unsigned long V_13 ,
int (* V_35)( struct V_7 * , const char * ) )
{
int V_27 ;
struct V_10 * V_11 = & V_28 . V_11 ;
F_14 ( & V_11 -> V_29 ) ;
V_11 -> V_14 = V_19 ;
V_11 -> V_20 = V_13 ;
V_11 -> V_30 = V_31 * 16 ;
V_11 -> V_32 = F_1 ( V_13 , V_46 ) ;
V_28 . V_33 -> V_34 = & V_28 ;
V_27 = V_35 ( & V_28 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
if ( ! V_28 . V_33 -> V_36 )
return - V_37 ;
F_15 ( V_28 . V_33 ) ;
return 0 ;
}
