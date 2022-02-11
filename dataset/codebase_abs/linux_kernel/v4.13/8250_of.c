static void F_1 ( struct V_1 * V_2 )
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
V_14 -> V_39 = F_17 ( & V_12 -> V_18 , NULL ) ;
if ( F_6 ( V_14 -> V_39 ) )
goto V_25;
V_23 = F_18 ( V_14 -> V_39 ) ;
if ( V_23 )
goto V_25;
V_10 -> type = type ;
V_10 -> V_40 = V_20 ;
V_10 -> V_41 = V_42 | V_43 | V_44
| V_45 | V_46 ;
if ( F_19 ( V_17 , L_11 , NULL ) )
V_10 -> V_41 |= V_47 ;
V_10 -> V_18 = & V_12 -> V_18 ;
switch ( type ) {
case V_48 :
V_10 -> V_49 = F_1 ;
break;
case V_50 :
V_10 -> V_33 = V_51 ;
break;
}
if ( F_20 ( V_52 ) &&
( F_21 ( V_17 , L_12 ) ||
F_21 ( V_17 , L_13 ) ) )
V_10 -> V_53 = V_54 ;
return 0 ;
V_25:
if ( V_14 -> V_20 )
F_22 ( V_14 -> V_20 ) ;
return V_23 ;
}
static int F_23 ( struct V_11 * V_12 )
{
const struct V_55 * V_56 ;
struct V_13 * V_14 ;
struct V_57 V_58 ;
T_1 V_59 ;
int V_60 ;
int V_23 ;
V_56 = F_24 ( V_61 , & V_12 -> V_18 ) ;
if ( ! V_56 )
return - V_38 ;
if ( F_19 ( V_12 -> V_18 . V_19 , L_14 , NULL ) )
return - V_62 ;
V_14 = F_25 ( sizeof( * V_14 ) , V_63 ) ;
if ( V_14 == NULL )
return - V_64 ;
V_60 = ( unsigned long ) V_56 -> V_65 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_23 = F_3 ( V_12 , V_60 , & V_58 . V_10 , V_14 ) ;
if ( V_23 )
goto V_25;
if ( V_58 . V_10 . V_31 )
V_58 . V_66 = V_67 ;
if ( ( F_4 ( V_12 -> V_18 . V_19 , L_15 ,
& V_59 ) == 0 ) &&
( V_59 < V_58 . V_10 . V_31 ) )
V_58 . V_68 = V_58 . V_10 . V_31 - V_59 ;
if ( F_26 ( V_12 -> V_18 . V_19 , L_16 ) )
V_58 . V_66 |= V_69 ;
V_23 = F_27 ( & V_58 ) ;
if ( V_23 < 0 )
goto V_25;
V_14 -> type = V_60 ;
V_14 -> line = V_23 ;
F_28 ( V_12 , V_14 ) ;
return 0 ;
V_25:
F_29 ( V_14 ) ;
F_30 ( V_58 . V_10 . V_32 ) ;
return V_23 ;
}
static int F_31 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_32 ( V_12 ) ;
F_33 ( V_14 -> line ) ;
F_34 ( V_14 -> V_39 ) ;
if ( V_14 -> V_20 )
F_22 ( V_14 -> V_20 ) ;
F_29 ( V_14 ) ;
return 0 ;
}
static int F_35 ( struct V_70 * V_18 )
{
struct V_13 * V_14 = F_36 ( V_18 ) ;
struct V_57 * V_58 = F_37 ( V_14 -> line ) ;
struct V_1 * V_10 = & V_58 -> V_10 ;
F_38 ( V_14 -> line ) ;
if ( V_14 -> V_20 && ( ! F_39 ( V_10 ) || V_71 ) )
F_22 ( V_14 -> V_20 ) ;
return 0 ;
}
static int F_40 ( struct V_70 * V_18 )
{
struct V_13 * V_14 = F_36 ( V_18 ) ;
struct V_57 * V_58 = F_37 ( V_14 -> line ) ;
struct V_1 * V_10 = & V_58 -> V_10 ;
if ( V_14 -> V_20 && ( ! F_39 ( V_10 ) || V_71 ) )
F_9 ( V_14 -> V_20 ) ;
F_41 ( V_14 -> line ) ;
return 0 ;
}
