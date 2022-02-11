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
F_4 ( & V_12 -> V_18 ) ;
F_5 ( & V_12 -> V_18 ) ;
if ( F_6 ( V_17 , L_1 , & V_20 ) ) {
V_14 -> V_20 = F_7 ( & V_12 -> V_18 , NULL ) ;
if ( F_8 ( V_14 -> V_20 ) ) {
F_9 ( & V_12 -> V_18 ,
L_2 ) ;
V_23 = F_10 ( V_14 -> V_20 ) ;
goto V_24;
}
V_23 = F_11 ( V_14 -> V_20 ) ;
if ( V_23 < 0 )
goto V_24;
V_20 = F_12 ( V_14 -> V_20 ) ;
}
if ( F_6 ( V_17 , L_3 , & V_21 ) == 0 )
V_10 -> V_25 = V_20 / ( 16 * V_21 ) ;
V_23 = F_13 ( V_17 , 0 , & V_15 ) ;
if ( V_23 ) {
F_9 ( & V_12 -> V_18 , L_4 ) ;
goto V_26;
}
F_14 ( & V_10 -> V_27 ) ;
V_10 -> V_28 = V_15 . V_29 ;
V_10 -> V_30 = F_15 ( & V_15 ) ;
if ( F_6 ( V_17 , L_5 , & V_22 ) == 0 )
V_10 -> V_28 += V_22 ;
if ( F_6 ( V_17 , L_6 , & V_22 ) == 0 )
V_10 -> V_31 = V_22 ;
if ( F_6 ( V_17 , L_7 , & V_22 ) == 0 )
V_10 -> V_32 = V_22 ;
V_23 = F_16 ( V_17 , L_8 ) ;
if ( V_23 >= 0 )
V_10 -> line = V_23 ;
V_10 -> V_33 = F_17 ( V_17 , 0 ) ;
V_10 -> V_34 = V_35 ;
if ( F_6 ( V_17 , L_9 , & V_22 ) == 0 ) {
switch ( V_22 ) {
case 1 :
V_10 -> V_34 = V_35 ;
break;
case 2 :
V_10 -> V_34 = V_36 ;
break;
case 4 :
V_10 -> V_34 = F_18 ( V_17 ) ?
V_37 : V_38 ;
break;
default:
F_9 ( & V_12 -> V_18 , L_10 ,
V_22 ) ;
V_23 = - V_39 ;
goto V_40;
}
}
V_14 -> V_41 = F_19 ( & V_12 -> V_18 , NULL ) ;
if ( F_8 ( V_14 -> V_41 ) )
goto V_40;
V_23 = F_20 ( V_14 -> V_41 ) ;
if ( V_23 )
goto V_40;
V_10 -> type = type ;
V_10 -> V_42 = V_20 ;
V_10 -> V_43 = V_44 | V_45 | V_46
| V_47 | V_48 ;
if ( F_21 ( V_17 , L_11 ) )
V_10 -> V_43 |= V_49 ;
V_10 -> V_18 = & V_12 -> V_18 ;
switch ( type ) {
case V_50 :
V_10 -> V_51 = F_1 ;
break;
case V_52 :
V_10 -> V_34 = V_53 ;
break;
}
if ( F_22 ( V_54 ) &&
( F_23 ( V_17 , L_12 ) ||
F_23 ( V_17 , L_13 ) ) )
V_10 -> V_55 = V_56 ;
return 0 ;
V_40:
F_24 ( V_10 -> V_33 ) ;
V_26:
F_25 ( V_14 -> V_20 ) ;
V_24:
F_26 ( & V_12 -> V_18 ) ;
F_27 ( & V_12 -> V_18 ) ;
return V_23 ;
}
static int F_28 ( struct V_11 * V_12 )
{
const struct V_57 * V_58 ;
struct V_13 * V_14 ;
struct V_59 V_60 ;
T_1 V_61 ;
int V_62 ;
int V_23 ;
V_58 = F_29 ( V_63 , & V_12 -> V_18 ) ;
if ( ! V_58 )
return - V_39 ;
if ( F_21 ( V_12 -> V_18 . V_19 , L_14 ) )
return - V_64 ;
V_14 = F_30 ( sizeof( * V_14 ) , V_65 ) ;
if ( V_14 == NULL )
return - V_66 ;
V_62 = ( unsigned long ) V_58 -> V_67 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_23 = F_3 ( V_12 , V_62 , & V_60 . V_10 , V_14 ) ;
if ( V_23 )
goto V_68;
if ( V_60 . V_10 . V_32 )
V_60 . V_69 = V_70 ;
if ( ( F_6 ( V_12 -> V_18 . V_19 , L_15 ,
& V_61 ) == 0 ) &&
( V_61 < V_60 . V_10 . V_32 ) )
V_60 . V_71 = V_60 . V_10 . V_32 - V_61 ;
if ( F_21 ( V_12 -> V_18 . V_19 , L_16 ) )
V_60 . V_69 |= V_72 ;
V_23 = F_31 ( & V_60 ) ;
if ( V_23 < 0 )
goto V_40;
V_14 -> type = V_62 ;
V_14 -> line = V_23 ;
F_32 ( V_12 , V_14 ) ;
return 0 ;
V_40:
F_24 ( V_60 . V_10 . V_33 ) ;
F_26 ( & V_12 -> V_18 ) ;
F_27 ( & V_12 -> V_18 ) ;
F_25 ( V_14 -> V_20 ) ;
V_68:
F_33 ( V_14 ) ;
return V_23 ;
}
static int F_34 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_35 ( V_12 ) ;
F_36 ( V_14 -> line ) ;
F_37 ( V_14 -> V_41 ) ;
F_26 ( & V_12 -> V_18 ) ;
F_27 ( & V_12 -> V_18 ) ;
F_25 ( V_14 -> V_20 ) ;
F_33 ( V_14 ) ;
return 0 ;
}
static int F_38 ( struct V_73 * V_18 )
{
struct V_13 * V_14 = F_39 ( V_18 ) ;
struct V_59 * V_60 = F_40 ( V_14 -> line ) ;
struct V_1 * V_10 = & V_60 -> V_10 ;
F_41 ( V_14 -> line ) ;
if ( ! F_42 ( V_10 ) || V_74 ) {
F_26 ( V_18 ) ;
F_25 ( V_14 -> V_20 ) ;
}
return 0 ;
}
static int F_43 ( struct V_73 * V_18 )
{
struct V_13 * V_14 = F_39 ( V_18 ) ;
struct V_59 * V_60 = F_40 ( V_14 -> line ) ;
struct V_1 * V_10 = & V_60 -> V_10 ;
if ( ! F_42 ( V_10 ) || V_74 ) {
F_5 ( V_18 ) ;
F_11 ( V_14 -> V_20 ) ;
}
F_44 ( V_14 -> line ) ;
return 0 ;
}
