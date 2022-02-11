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
case 2 :
V_10 -> V_33 = V_35 ;
break;
case 4 :
V_10 -> V_33 = F_16 ( V_17 ) ?
V_36 : V_37 ;
break;
default:
F_7 ( & V_12 -> V_18 , L_10 ,
V_22 ) ;
V_23 = - V_38 ;
goto V_25;
}
}
V_10 -> type = type ;
V_10 -> V_39 = V_20 ;
V_10 -> V_40 = V_41 | V_42 | V_43
| V_44 | V_45 ;
if ( F_17 ( V_17 , L_11 , NULL ) )
V_10 -> V_40 |= V_46 ;
V_10 -> V_18 = & V_12 -> V_18 ;
switch ( type ) {
case V_47 :
V_10 -> V_48 = F_1 ;
break;
case V_49 :
V_10 -> V_33 = V_50 ;
break;
}
if ( F_18 ( V_51 ) &&
( F_19 ( V_17 , L_12 ) ||
F_19 ( V_17 , L_13 ) ) )
V_10 -> V_52 = V_53 ;
return 0 ;
V_25:
if ( V_14 -> V_20 )
F_20 ( V_14 -> V_20 ) ;
return V_23 ;
}
static int F_21 ( struct V_11 * V_12 )
{
const struct V_54 * V_55 ;
struct V_13 * V_14 ;
struct V_1 V_10 ;
int V_56 ;
int V_23 ;
V_55 = F_22 ( V_57 , & V_12 -> V_18 ) ;
if ( ! V_55 )
return - V_38 ;
if ( F_17 ( V_12 -> V_18 . V_19 , L_14 , NULL ) )
return - V_58 ;
V_14 = F_23 ( sizeof( * V_14 ) , V_59 ) ;
if ( V_14 == NULL )
return - V_60 ;
V_56 = ( unsigned long ) V_55 -> V_61 ;
V_23 = F_3 ( V_12 , V_56 , & V_10 , V_14 ) ;
if ( V_23 )
goto V_25;
switch ( V_56 ) {
case V_62 ... V_63 :
{
struct V_64 V_65 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_10 = V_10 ;
if ( V_10 . V_31 )
V_65 . V_66 = V_67 ;
if ( F_24 ( V_12 -> V_18 . V_19 ,
L_15 ) )
V_65 . V_66 |= V_68 ;
V_23 = F_25 ( & V_65 ) ;
break;
}
default:
case V_69 :
F_26 ( & V_12 -> V_18 , L_16 ) ;
V_23 = - V_70 ;
break;
}
if ( V_23 < 0 )
goto V_25;
V_14 -> type = V_56 ;
V_14 -> line = V_23 ;
F_27 ( V_12 , V_14 ) ;
return 0 ;
V_25:
F_28 ( V_14 ) ;
F_29 ( V_10 . V_32 ) ;
return V_23 ;
}
static int F_30 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_31 ( V_12 ) ;
switch ( V_14 -> type ) {
case V_62 ... V_63 :
F_32 ( V_14 -> line ) ;
break;
default:
break;
}
if ( V_14 -> V_20 )
F_20 ( V_14 -> V_20 ) ;
F_28 ( V_14 ) ;
return 0 ;
}
static void F_33 ( struct V_13 * V_14 )
{
struct V_64 * V_65 = F_34 ( V_14 -> line ) ;
struct V_1 * V_10 = & V_65 -> V_10 ;
F_35 ( V_14 -> line ) ;
if ( V_14 -> V_20 && ( ! F_36 ( V_10 ) || V_71 ) )
F_20 ( V_14 -> V_20 ) ;
}
static void F_37 ( struct V_13 * V_14 )
{
struct V_64 * V_65 = F_34 ( V_14 -> line ) ;
struct V_1 * V_10 = & V_65 -> V_10 ;
if ( V_14 -> V_20 && ( ! F_36 ( V_10 ) || V_71 ) )
F_9 ( V_14 -> V_20 ) ;
F_38 ( V_14 -> line ) ;
}
static int F_39 ( struct V_72 * V_18 )
{
struct V_13 * V_14 = F_40 ( V_18 ) ;
switch ( V_14 -> type ) {
case V_62 ... V_63 :
F_33 ( V_14 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_41 ( struct V_72 * V_18 )
{
struct V_13 * V_14 = F_40 ( V_18 ) ;
switch ( V_14 -> type ) {
case V_62 ... V_63 :
F_37 ( V_14 ) ;
break;
default:
break;
}
return 0 ;
}
