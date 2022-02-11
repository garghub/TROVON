static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 ) ;
}
int F_4 ( struct V_3 * V_4 )
{
int V_6 = 0 ;
V_4 -> V_7 = F_5 ( L_1 ,
V_8 | V_9
| V_10 , 1 ) ;
if ( ! V_4 -> V_7 )
return - V_11 ;
F_6 ( & V_4 -> V_5 , F_1 ) ;
F_7 ( L_2 ) ;
F_8 ( & V_4 -> V_12 , 0 ) ;
F_8 ( & V_4 -> V_13 , 0 ) ;
F_8 ( & V_4 -> V_14 , 0 ) ;
F_8 ( & V_4 -> V_15 , V_16 ) ;
V_4 -> V_17 = 0 ;
V_4 -> V_18 = 0 ;
V_4 -> V_19 = 0 ;
V_4 -> V_20 = 0 ;
F_9 ( & V_4 -> V_21 ) ;
F_9 ( & V_4 -> V_22 ) ;
V_6 = ! F_10 ( V_4 -> V_7 , & V_4 -> V_5 ) ;
F_11 ( V_6 ) ;
return V_6 ;
}
void F_12 ( struct V_3 * V_4 )
{
F_13 ( 1 , & V_4 -> V_14 ) ;
F_14 ( & V_4 -> V_21 ) ;
F_15 ( V_4 -> V_7 ) ;
F_16 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
F_7 ( L_3 ) ;
}
void F_17 ( struct V_3 * V_4 )
{
F_7 ( L_4 ) ;
F_18 ( V_4 , 0 ) ;
if ( ( V_4 -> V_17 ) )
return;
if ( F_19 ( 1 , & V_4 -> V_12 ) == 1 )
F_14 ( & V_4 -> V_21 ) ;
}
void F_20 ( struct V_3 * V_4 )
{
F_7 ( L_5 ) ;
if ( V_4 -> V_17 ) {
F_21 ( L_6 ) ;
return;
}
if ( F_19 ( 1 , & V_4 -> V_13 ) == 1 )
F_14 ( & V_4 -> V_21 ) ;
}
int F_22 ( struct V_3 * V_4 )
{
F_7 ( L_7 ) ;
if ( V_4 -> V_17 ) {
F_23 ( V_4 -> V_23 -> V_24 , L_8 ) ;
return - V_25 ;
}
F_8 ( & V_4 -> V_15 , V_26 ) ;
F_14 ( & V_4 -> V_21 ) ;
return F_24 ( V_4 -> V_22 , V_4 -> V_17 ||
( V_27 == F_25 ( & V_4 -> V_15 ) ) ,
1 * V_28 ) ? 0 : - V_29 ;
}
int F_26 ( struct V_3 * V_4 )
{
F_7 ( L_9 ) ;
if ( V_4 -> V_17 ) {
F_23 ( V_4 -> V_23 -> V_24 , L_10 ) ;
return - V_25 ;
}
F_8 ( & V_4 -> V_15 , V_30 ) ;
F_14 ( & V_4 -> V_21 ) ;
return F_24 ( V_4 -> V_22 , V_4 -> V_17 ||
( V_16 == F_25 ( & V_4 -> V_15 ) ) ,
1 * V_28 ) ? 0 : - V_29 ;
}
static inline void F_27 ( struct V_3 * V_4 )
{
++ V_4 -> V_18 ;
}
int F_28 ( struct V_3 * V_4 , int V_31 )
{
int V_32 = 0 ;
int V_18 = V_4 -> V_18 ;
V_4 -> V_18 -= V_31 ;
if ( F_11 ( V_4 -> V_18 < 0 ) )
V_32 = - 1 ;
else if ( V_18 >= V_4 -> V_33 . V_34 )
V_32 = 1 ;
if ( ! V_4 -> V_18 )
F_14 ( & V_4 -> V_22 ) ;
return V_32 ;
}
static int F_29 ( struct V_3 * V_4 ,
T_1 * V_35 )
{
int V_32 ;
V_32 = F_30 ( V_4 ,
V_36 , V_35 ) ;
if ( V_32 ) {
V_32 = F_30 ( V_4 ,
V_36 , V_35 ) ;
if ( V_32 )
F_21 ( L_11 ) ;
}
return V_32 ;
}
static int F_31 ( struct V_3 * V_4 )
{
T_1 V_35 ;
int V_32 ;
F_7 ( L_12 ) ;
V_32 = F_32 ( V_4 , V_37 ,
F_33 ( V_4 -> V_38 ) ) ;
if ( F_11 ( V_32 ) )
return V_32 ;
V_32 = F_34 ( V_4 , V_36 ,
V_39 ) ;
if ( F_11 ( V_32 ) )
return V_32 ;
V_32 = F_29 ( V_4 , & V_35 ) ;
if ( F_11 ( V_32 ) )
return V_32 ;
if ( V_35 & V_40 ) {
F_7 ( L_13 ) ;
return 1 ;
}
return 0 ;
}
void F_35 ( struct V_3 * V_4 ,
bool V_41 )
{
F_7 ( L_14 ,
V_41 ? L_15 : L_16 ) ;
V_4 -> V_42 = V_41 ;
}
static int F_36 ( struct V_3 * V_4 ,
T_2 * V_35 ,
int * V_43 )
{
T_3 V_44 = 0 ;
struct V_45 * V_46 = NULL ;
struct V_47 * V_48 ;
T_3 V_49 ;
T_1 V_50 ;
T_4 V_51 ;
int V_52 = 1 ;
T_3 V_53 ;
T_4 * V_54 ;
V_44 = ( * V_35 & V_55 ) * 2 ;
if ( ! V_44 )
return 0 ;
if ( F_11 ( ( V_44 < sizeof( struct V_47 ) ) ||
( V_44 > V_56 ) ) ) {
F_7 ( L_17 ,
V_44 , * V_35 ) ;
goto V_6;
}
V_44 = V_44 + 2 ;
V_53 = V_4 -> V_57 -> V_58 (
V_4 -> V_59 , V_44 ) ;
if ( F_37 ( V_53 > V_56 ) ) {
F_7 ( L_18 ,
V_53 ) ;
}
V_46 = F_38 ( V_53 ) ;
if ( F_11 ( ! V_46 ) )
goto V_6;
F_39 ( V_46 , 0 ) ;
F_40 ( V_46 , V_44 ) ;
V_54 = V_46 -> V_54 ;
if ( F_11 ( ! V_54 ) )
goto V_6;
if ( F_11 ( F_41 ( V_4 , V_54 , V_53 ) ) ) {
F_21 ( L_19 , V_53 ) ;
goto V_6;
}
* V_35 = F_42 (
( ( V_60 * ) V_54 ) [ V_53 / 2 - 1 ] ) ;
V_48 = (struct V_47 * ) V_54 ;
V_49 = F_42 ( V_48 -> V_61 ) ;
if ( F_11 ( V_49 > V_44 ) )
goto V_6;
if ( V_4 -> V_62 )
F_43 ( L_20 ,
V_63 ,
V_54 , V_49 ) ;
V_50 = F_42 ( V_48 -> V_64 ) & 0xFFF ;
V_51 = ( F_42 ( V_48 -> V_64 ) >> 13 ) & 7 ;
F_39 ( V_46 , V_49 ) ;
if ( V_50 == 0x0800 ) {
F_44 ( V_4 ,
& V_54 [ sizeof( * V_48 ) ] ,
V_49 - sizeof( * V_48 ) ) ;
goto V_6;
} else if ( ! V_52 ) {
if ( F_11 ( V_51 != V_4 -> V_65 ) )
goto V_6;
}
V_4 -> V_65 = ( V_51 + 1 ) & 7 ;
V_52 = 0 ;
if ( V_50 & 0x0400 ) {
int V_66 = F_28 ( V_4 , 1 ) ;
if ( F_11 ( V_66 < 0 ) )
return V_66 ;
else if ( V_66 > 0 )
* V_43 = 1 ;
}
if ( F_11 ( F_45 ( V_4 , V_50 , V_48 , & V_46 ) ) )
goto V_6;
if ( V_46 ) {
F_46 ( V_46 ) ;
V_46 = NULL ;
}
return 0 ;
V_6:
if ( V_46 ) {
F_46 ( V_46 ) ;
V_46 = NULL ;
}
return - 1 ;
}
static int F_47 ( struct V_3 * V_4 ,
int * V_67 ,
int * V_68 )
{
T_3 V_69 ;
T_4 * V_54 ;
int V_32 ;
struct V_47 * V_48 ;
if ( V_4 -> V_70 ) {
V_32 = F_31 ( V_4 ) ;
if ( F_11 ( V_32 < 0 ) ) {
* V_67 = 1 ;
return 0 ;
} else if ( V_32 ) {
V_4 -> V_70 = false ;
} else {
* V_67 = 1 ;
return 0 ;
}
}
F_27 ( V_4 ) ;
V_32 = F_48 ( V_4 , & V_54 , & V_69 , V_68 ) ;
if ( V_32 <= 0 ) {
F_28 ( V_4 , 1 ) ;
if ( F_11 ( V_32 < 0 ) )
return V_32 ;
return 0 ;
}
V_48 = (struct V_47 * ) V_54 ;
F_49 ( V_69 < sizeof( * V_48 ) ) ;
F_49 ( F_42 ( V_48 -> V_61 ) != V_69 ) ;
F_13 ( 1 , & V_4 -> V_13 ) ;
V_69 = V_4 -> V_57 -> V_58 (
V_4 -> V_59 , V_69 ) ;
if ( F_37 ( V_69 > V_56 ) )
F_7 ( L_21 , V_69 ) ;
V_48 -> V_64 &= F_50 ( 0xffff ^ F_51 ( V_71 ) ) ;
V_48 -> V_64 |= F_50 ( F_51 ( V_4 -> V_72 ) ) ;
if ( F_11 ( F_52 ( V_4 , V_54 , V_69 ) ) ) {
F_21 ( L_22 , V_69 ) ;
F_28 ( V_4 , 1 ) ;
return - 1 ;
}
if ( V_4 -> V_62 )
F_43 ( L_23 ,
V_63 ,
V_54 ,
F_42 ( V_48 -> V_61 ) ) ;
F_53 ( V_4 , V_54 ) ;
V_4 -> V_72 = ( V_4 -> V_72 + 1 ) & V_71 ;
if ( * V_68 > 1 ) {
F_54 ( V_4 ) ;
return 1 ;
}
return 0 ;
}
static int F_3 ( void * V_73 )
{
struct V_3 * V_4 = V_73 ;
int V_74 , V_43 , V_75 , V_76 ;
T_1 V_35 = 0 ;
int V_77 ;
int V_67 = 0 ;
int V_68 ;
long V_78 ;
T_5 V_79 ;
int V_32 ;
for (; ; ) {
if ( ! V_4 -> V_18 &&
V_4 -> V_42 &&
! V_4 -> V_70 &&
! F_25 ( & V_4 -> V_80 ) ) {
V_78 = 1 * V_28 ;
F_7 ( L_24 ) ;
F_34 ( V_4 , V_36 , 0 ) ;
V_4 -> V_70 = true ;
} else if ( V_4 -> V_18 ) {
V_78 = 1 * V_28 ;
} else {
V_78 = V_81 ;
}
if ( ( V_4 -> V_82 != - 1 ) &&
( F_25 ( & V_4 -> V_12 ) == 0 ) &&
( F_25 ( & V_4 -> V_13 ) == 0 ) )
F_55 ( V_4 , V_83 ,
& V_79 , sizeof( V_79 ) ) ;
F_7 ( L_25 ) ;
V_78 = F_56 (priv->bh_wq, ({
rx = atomic_xchg(&priv->bh_rx, 0);
tx = atomic_xchg(&priv->bh_tx, 0);
term = atomic_xchg(&priv->bh_term, 0);
suspend = pending_tx ?
0 : atomic_read(&priv->bh_suspend);
(rx || tx || term || suspend || priv->bh_error);
}), status) ;
F_7 ( L_26 ,
V_74 , V_43 , V_75 , V_76 , V_78 ) ;
if ( ( V_78 < 0 && V_78 != - V_84 ) ||
V_75 || V_4 -> V_17 ) {
break;
}
if ( ! V_78 ) {
unsigned long V_85 = V_86 ;
long V_87 ;
int V_88 = 0 ;
int V_89 ;
if ( V_4 -> V_18 && ( ! V_74 || ! V_43 ) ) {
F_23 ( V_4 -> V_23 -> V_24 ,
L_27 ,
V_4 -> V_18 ) ;
V_74 = 1 ;
for ( V_89 = 0 ; V_89 < 4 ; ++ V_89 )
V_88 += F_57 (
& V_4 -> V_90 [ V_89 ] ,
& V_85 ,
V_4 -> V_91 ) ;
V_87 = V_85 +
V_92 +
1 * V_28 -
V_86 ;
if ( V_88 && V_87 < 0 ) {
F_23 ( V_4 -> V_23 -> V_24 ,
L_28 ,
V_4 -> V_18 , V_88 ,
V_85 , V_86 ) ;
break;
}
} else if ( ! V_4 -> V_70 &&
! F_25 ( & V_4 -> V_80 ) ) {
F_7 ( L_29 ) ;
F_34 ( V_4 ,
V_36 , 0 ) ;
V_4 -> V_70 = true ;
}
goto V_93;
} else if ( V_76 ) {
F_7 ( L_30 ) ;
if ( V_4 -> V_42 ) {
F_7 ( L_31 ) ;
F_34 ( V_4 ,
V_36 , 0 ) ;
V_4 -> V_70 = true ;
}
F_8 ( & V_4 -> V_15 , V_27 ) ;
F_14 ( & V_4 -> V_22 ) ;
V_78 = F_58 ( V_4 -> V_21 ,
V_30 == F_25 ( & V_4 -> V_15 ) ) ;
if ( V_78 < 0 ) {
F_59 ( V_4 -> V_23 -> V_24 ,
L_32 ,
V_78 ) ;
break;
}
F_7 ( L_33 ) ;
F_8 ( & V_4 -> V_15 , V_16 ) ;
F_14 ( & V_4 -> V_22 ) ;
F_13 ( 1 , & V_4 -> V_12 ) ;
goto V_93;
}
V_74:
V_43 += V_67 ;
V_67 = 0 ;
if ( F_29 ( V_4 , & V_35 ) )
break;
if ( V_35 & V_55 ) {
V_32 = F_36 ( V_4 , & V_35 , & V_43 ) ;
if ( V_32 < 0 )
break;
if ( V_35 & V_55 ) {
V_32 = F_36 ( V_4 , & V_35 , & V_43 ) ;
if ( V_32 < 0 )
break;
}
}
V_43:
if ( V_43 ) {
V_43 = 0 ;
F_49 ( V_4 -> V_18 > V_4 -> V_33 . V_34 ) ;
V_68 = V_4 -> V_33 . V_34 - V_4 -> V_18 ;
V_77 = V_68 > 0 ;
if ( ! V_77 ) {
V_67 = V_43 ;
goto V_94;
}
V_32 = F_47 ( V_4 , & V_67 , & V_68 ) ;
if ( V_32 < 0 )
break;
if ( V_32 > 0 )
V_43 = V_32 ;
if ( F_29 ( V_4 , & V_35 ) )
break;
}
V_94:
if ( V_4 -> V_17 )
break;
if ( V_35 & V_55 )
goto V_74;
if ( V_43 )
goto V_43;
V_93:
V_4 -> V_57 -> V_95 ( V_4 -> V_59 ) ;
F_18 ( V_4 , 1 ) ;
V_4 -> V_57 -> V_96 ( V_4 -> V_59 ) ;
}
V_4 -> V_57 -> V_95 ( V_4 -> V_59 ) ;
F_18 ( V_4 , 0 ) ;
V_4 -> V_57 -> V_96 ( V_4 -> V_59 ) ;
if ( ! V_75 ) {
F_21 ( L_34 ) ;
V_4 -> V_17 = 1 ;
}
return 0 ;
}
