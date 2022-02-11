void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 = 10000 ;
do {
V_3 = V_2 -> V_5 ( V_2 , V_6 ) ;
if ( V_3 & ( V_7 | V_8 ) )
V_3 = V_2 -> V_5 ( V_2 , V_9 ) ;
else
break;
if ( -- V_4 == 0 )
break;
F_2 ( 1 ) ;
} while ( 1 );
}
static int T_1 F_3 ( struct V_10 * V_11 ,
int type , struct V_1 * V_12 )
{
struct V_13 V_13 ;
struct V_14 * V_15 = V_11 -> V_16 . V_17 ;
T_2 V_18 , V_19 , V_20 ;
int V_21 ;
memset ( V_12 , 0 , sizeof *V_12 ) ;
if ( F_4 ( V_15 , L_1 , & V_18 ) ) {
F_5 ( & V_11 -> V_16 , L_2 ) ;
return - V_22 ;
}
if ( F_4 ( V_15 , L_3 , & V_19 ) == 0 )
V_12 -> V_23 = V_18 / ( 16 * V_19 ) ;
V_21 = F_6 ( V_15 , 0 , & V_13 ) ;
if ( V_21 ) {
F_5 ( & V_11 -> V_16 , L_4 ) ;
return V_21 ;
}
F_7 ( & V_12 -> V_24 ) ;
V_12 -> V_25 = V_13 . V_26 ;
if ( F_4 ( V_15 , L_5 , & V_20 ) == 0 )
V_12 -> V_25 += V_20 ;
if ( F_4 ( V_15 , L_6 , & V_20 ) == 0 )
V_12 -> V_27 = V_20 ;
V_12 -> V_28 = F_8 ( V_15 , 0 ) ;
V_12 -> V_29 = V_30 ;
if ( F_4 ( V_15 , L_7 , & V_20 ) == 0 ) {
switch ( V_20 ) {
case 1 :
V_12 -> V_29 = V_30 ;
break;
case 4 :
V_12 -> V_29 = V_31 ;
break;
default:
F_5 ( & V_11 -> V_16 , L_8 ,
V_20 ) ;
return - V_32 ;
}
}
V_12 -> type = type ;
V_12 -> V_33 = V_18 ;
V_12 -> V_34 = V_35 | V_36 | V_37
| V_38 | V_39 ;
if ( F_9 ( V_15 , L_9 , NULL ) )
V_12 -> V_34 |= V_40 ;
V_12 -> V_16 = & V_11 -> V_16 ;
if ( type == V_41 )
V_12 -> V_42 = F_1 ;
return 0 ;
}
static int T_1 F_10 ( struct V_10 * V_11 )
{
const struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_1 V_12 ;
int V_47 ;
int V_21 ;
V_44 = F_11 ( V_48 , & V_11 -> V_16 ) ;
if ( ! V_44 )
return - V_32 ;
if ( F_9 ( V_11 -> V_16 . V_17 , L_10 , NULL ) )
return - V_49 ;
V_46 = F_12 ( sizeof( * V_46 ) , V_50 ) ;
if ( V_46 == NULL )
return - V_51 ;
V_47 = ( unsigned long ) V_44 -> V_52 ;
V_21 = F_3 ( V_11 , V_47 , & V_12 ) ;
if ( V_21 )
goto V_53;
switch ( V_47 ) {
#ifdef F_13
case V_54 ... V_55 :
{
struct V_56 V_57 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_12 = V_12 ;
V_21 = F_14 ( & V_57 ) ;
break;
}
#endif
#ifdef F_15
case V_58 :
V_21 = F_16 ( & V_12 ) ;
break;
#endif
default:
case V_59 :
F_17 ( & V_11 -> V_16 , L_11 ) ;
V_21 = - V_22 ;
break;
}
if ( V_21 < 0 )
goto V_53;
V_46 -> type = V_47 ;
V_46 -> line = V_21 ;
F_18 ( & V_11 -> V_16 , V_46 ) ;
return 0 ;
V_53:
F_19 ( V_46 ) ;
F_20 ( V_12 . V_28 ) ;
return V_21 ;
}
static int F_21 ( struct V_10 * V_11 )
{
struct V_45 * V_46 = F_22 ( & V_11 -> V_16 ) ;
switch ( V_46 -> type ) {
#ifdef F_13
case V_54 ... V_55 :
F_23 ( V_46 -> line ) ;
break;
#endif
#ifdef F_15
case V_58 :
F_24 ( V_46 -> line ) ;
break;
#endif
default:
break;
}
F_19 ( V_46 ) ;
return 0 ;
}
