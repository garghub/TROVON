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
V_23 = F_9 ( V_14 -> V_20 ) ;
if ( V_23 < 0 )
return V_23 ;
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
V_10 -> V_29 = F_13 ( & V_15 ) ;
if ( F_4 ( V_17 , L_5 , & V_22 ) == 0 )
V_10 -> V_27 += V_22 ;
if ( F_4 ( V_17 , L_6 , & V_22 ) == 0 )
V_10 -> V_30 = V_22 ;
if ( F_4 ( V_17 , L_7 , & V_22 ) == 0 )
V_10 -> V_31 = V_22 ;
V_23 = F_14 ( V_17 , L_8 ) ;
if ( V_23 >= 0 )
V_10 -> line = V_23 ;
V_10 -> V_32 = F_15 ( V_17 , 0 ) ;
V_10 -> V_33 = V_34 ;
if ( F_4 ( V_17 , L_9 , & V_22 ) == 0 ) {
switch ( V_22 ) {
case 1 :
V_10 -> V_33 = V_34 ;
break;
case 4 :
V_10 -> V_33 = F_16 ( V_17 ) ?
V_35 : V_36 ;
break;
default:
F_7 ( & V_12 -> V_18 , L_10 ,
V_22 ) ;
V_23 = - V_37 ;
goto V_25;
}
}
V_10 -> type = type ;
V_10 -> V_38 = V_20 ;
V_10 -> V_39 = V_40 | V_41 | V_42
| V_43 | V_44 ;
if ( F_17 ( V_17 , L_11 , NULL ) )
V_10 -> V_39 |= V_45 ;
V_10 -> V_18 = & V_12 -> V_18 ;
switch ( type ) {
case V_46 :
V_10 -> V_47 = F_1 ;
break;
case V_48 :
V_10 -> V_33 = V_49 ;
break;
}
return 0 ;
V_25:
if ( V_14 -> V_20 )
F_18 ( V_14 -> V_20 ) ;
return V_23 ;
}
static int F_19 ( struct V_11 * V_12 )
{
const struct V_50 * V_51 ;
struct V_13 * V_14 ;
struct V_1 V_10 ;
int V_52 ;
int V_23 ;
V_51 = F_20 ( V_53 , & V_12 -> V_18 ) ;
if ( ! V_51 )
return - V_37 ;
if ( F_17 ( V_12 -> V_18 . V_19 , L_12 , NULL ) )
return - V_54 ;
V_14 = F_21 ( sizeof( * V_14 ) , V_55 ) ;
if ( V_14 == NULL )
return - V_56 ;
V_52 = ( unsigned long ) V_51 -> V_57 ;
V_23 = F_3 ( V_12 , V_52 , & V_10 , V_14 ) ;
if ( V_23 )
goto V_25;
switch ( V_52 ) {
#ifdef F_22
case V_58 ... V_59 :
{
struct V_60 V_61 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_10 = V_10 ;
if ( V_10 . V_31 )
V_61 . V_62 = V_63 ;
if ( F_23 ( V_12 -> V_18 . V_19 ,
L_13 ) )
V_61 . V_62 |= V_64 ;
V_23 = F_24 ( & V_61 ) ;
break;
}
#endif
#ifdef F_25
case V_65 :
V_23 = F_26 ( & V_10 ) ;
break;
#endif
default:
case V_66 :
F_27 ( & V_12 -> V_18 , L_14 ) ;
V_23 = - V_67 ;
break;
}
if ( V_23 < 0 )
goto V_25;
V_14 -> type = V_52 ;
V_14 -> line = V_23 ;
F_28 ( V_12 , V_14 ) ;
return 0 ;
V_25:
F_29 ( V_14 ) ;
F_30 ( V_10 . V_32 ) ;
return V_23 ;
}
static int F_31 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_32 ( V_12 ) ;
switch ( V_14 -> type ) {
#ifdef F_22
case V_58 ... V_59 :
F_33 ( V_14 -> line ) ;
break;
#endif
#ifdef F_25
case V_65 :
F_34 ( V_14 -> line ) ;
break;
#endif
default:
break;
}
if ( V_14 -> V_20 )
F_18 ( V_14 -> V_20 ) ;
F_29 ( V_14 ) ;
return 0 ;
}
static void F_35 ( struct V_13 * V_14 )
{
struct V_60 * V_61 = F_36 ( V_14 -> line ) ;
struct V_1 * V_10 = & V_61 -> V_10 ;
F_37 ( V_14 -> line ) ;
if ( V_14 -> V_20 && ( ! F_38 ( V_10 ) || V_68 ) )
F_18 ( V_14 -> V_20 ) ;
}
static void F_39 ( struct V_13 * V_14 )
{
struct V_60 * V_61 = F_36 ( V_14 -> line ) ;
struct V_1 * V_10 = & V_61 -> V_10 ;
if ( V_14 -> V_20 && ( ! F_38 ( V_10 ) || V_68 ) )
F_9 ( V_14 -> V_20 ) ;
F_40 ( V_14 -> line ) ;
}
static inline void F_35 ( struct V_13 * V_14 )
{
}
static inline void F_39 ( struct V_13 * V_14 )
{
}
static int F_41 ( struct V_69 * V_18 )
{
struct V_13 * V_14 = F_42 ( V_18 ) ;
switch ( V_14 -> type ) {
case V_58 ... V_59 :
F_35 ( V_14 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_43 ( struct V_69 * V_18 )
{
struct V_13 * V_14 = F_42 ( V_18 ) ;
switch ( V_14 -> type ) {
case V_58 ... V_59 :
F_39 ( V_14 ) ;
break;
default:
break;
}
return 0 ;
}
