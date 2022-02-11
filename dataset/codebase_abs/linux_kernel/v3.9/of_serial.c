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
static inline void F_1 ( struct V_1 * V_10 )
{
}
static int F_3 ( struct V_11 * V_12 ,
int type , struct V_1 * V_10 ,
struct V_13 * V_14 )
{
struct V_15 V_15 ;
struct V_16 * V_17 = V_12 -> V_18 . V_19 ;
T_1 V_20 , V_21 , V_22 ;
int V_23 ;
memset ( V_10 , 0 , sizeof *V_10 ) ;
if ( F_4 ( V_17 , L_1 , & V_20 ) ) {
V_14 -> V_20 = F_5 ( & V_12 -> V_18 , NULL ) ;
if ( F_6 ( V_14 -> V_20 ) ) {
F_7 ( & V_12 -> V_18 ,
L_2 ) ;
return F_8 ( V_14 -> V_20 ) ;
}
F_9 ( V_14 -> V_20 ) ;
V_20 = F_10 ( V_14 -> V_20 ) ;
}
if ( F_4 ( V_17 , L_3 , & V_21 ) == 0 )
V_10 -> V_24 = V_20 / ( 16 * V_21 ) ;
V_23 = F_11 ( V_17 , 0 , & V_15 ) ;
if ( V_23 ) {
F_7 ( & V_12 -> V_18 , L_4 ) ;
goto V_25;
}
F_12 ( & V_10 -> V_26 ) ;
V_10 -> V_27 = V_15 . V_28 ;
if ( F_4 ( V_17 , L_5 , & V_22 ) == 0 )
V_10 -> V_27 += V_22 ;
if ( F_4 ( V_17 , L_6 , & V_22 ) == 0 )
V_10 -> V_29 = V_22 ;
V_10 -> V_30 = F_13 ( V_17 , 0 ) ;
V_10 -> V_31 = V_32 ;
if ( F_4 ( V_17 , L_7 , & V_22 ) == 0 ) {
switch ( V_22 ) {
case 1 :
V_10 -> V_31 = V_32 ;
break;
case 4 :
V_10 -> V_31 = V_33 ;
break;
default:
F_7 ( & V_12 -> V_18 , L_8 ,
V_22 ) ;
V_23 = - V_34 ;
goto V_25;
}
}
V_10 -> type = type ;
V_10 -> V_35 = V_20 ;
V_10 -> V_36 = V_37 | V_38 | V_39
| V_40 | V_41 ;
if ( F_14 ( V_17 , L_9 , NULL ) )
V_10 -> V_36 |= V_42 ;
V_10 -> V_18 = & V_12 -> V_18 ;
if ( type == V_43 )
V_10 -> V_44 = F_1 ;
return 0 ;
V_25:
if ( V_14 -> V_20 )
F_15 ( V_14 -> V_20 ) ;
return V_23 ;
}
static int F_16 ( struct V_11 * V_12 )
{
const struct V_45 * V_46 ;
struct V_13 * V_14 ;
struct V_1 V_10 ;
int V_47 ;
int V_23 ;
V_46 = F_17 ( V_48 , & V_12 -> V_18 ) ;
if ( ! V_46 )
return - V_34 ;
if ( F_14 ( V_12 -> V_18 . V_19 , L_10 , NULL ) )
return - V_49 ;
V_14 = F_18 ( sizeof( * V_14 ) , V_50 ) ;
if ( V_14 == NULL )
return - V_51 ;
V_47 = ( unsigned long ) V_46 -> V_52 ;
V_23 = F_3 ( V_12 , V_47 , & V_10 , V_14 ) ;
if ( V_23 )
goto V_25;
switch ( V_47 ) {
#ifdef F_19
case V_53 ... V_54 :
{
struct V_55 V_56 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_10 = V_10 ;
V_23 = F_20 ( & V_56 ) ;
break;
}
#endif
#ifdef F_21
case V_57 :
V_23 = F_22 ( & V_10 ) ;
break;
#endif
default:
case V_58 :
F_23 ( & V_12 -> V_18 , L_11 ) ;
V_23 = - V_59 ;
break;
}
if ( V_23 < 0 )
goto V_25;
V_14 -> type = V_47 ;
V_14 -> line = V_23 ;
F_24 ( & V_12 -> V_18 , V_14 ) ;
return 0 ;
V_25:
F_25 ( V_14 ) ;
F_26 ( V_10 . V_30 ) ;
return V_23 ;
}
static int F_27 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_28 ( & V_12 -> V_18 ) ;
switch ( V_14 -> type ) {
#ifdef F_19
case V_53 ... V_54 :
F_29 ( V_14 -> line ) ;
break;
#endif
#ifdef F_21
case V_57 :
F_30 ( V_14 -> line ) ;
break;
#endif
default:
break;
}
if ( V_14 -> V_20 )
F_15 ( V_14 -> V_20 ) ;
F_25 ( V_14 ) ;
return 0 ;
}
