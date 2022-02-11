static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = F_2 ( V_2 , V_4 ) ;
int V_6 ;
F_3 ( V_7 L_1
L_2 ,
F_4 ( V_2 , V_4 ) , F_5 ( V_2 , V_4 ) ,
F_6 ( V_2 , V_4 ) , V_5 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
F_3 ( V_7 L_3 , V_6 ,
F_7 ( V_2 , V_4 , V_6 ) ,
F_8 ( V_2 , V_4 , V_6 ) ) ;
}
}
static void F_9 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_3 ( V_7 L_4
L_5 ,
F_10 ( V_2 , V_9 ) ,
F_11 ( V_2 , V_9 ) ,
F_12 ( V_2 , V_9 ) ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_3 ( V_7 L_6
L_7 ,
F_14 ( V_2 , V_11 ) ,
F_15 ( V_2 , V_11 ) ,
F_16 ( V_2 , V_11 ) ,
F_17 ( V_2 , V_11 ) ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_10 * V_17 ;
struct V_18 * V_19 ;
struct V_20 V_21 ;
unsigned long V_22 ;
unsigned long V_23 ;
int type ;
T_1 V_24 = F_19 ( V_2 , V_12 ) ;
T_2 V_25 ;
T_2 V_26 ;
if ( V_24 < sizeof( * V_14 ) ) {
#ifdef F_20
struct V_27 * V_28 ;
F_21 ( V_24 != sizeof( * V_28 ) ) ;
V_28 = F_22 ( V_2 , V_12 , struct V_27 ) ;
F_3 ( V_7 L_8 ,
F_23 ( V_2 , V_28 ) ) ;
return;
#else
F_24 () ;
#endif
}
V_14 = F_22 ( V_2 , V_12 , struct V_13 ) ;
V_25 = F_25 ( V_2 , V_14 ) ;
F_3 ( V_7 L_9 ,
F_26 ( V_2 , V_14 ) , F_27 ( V_2 , V_14 ) ,
V_25 ) ;
if ( V_25 & V_29 ) {
struct V_30 * V_31 ;
V_31 = (struct V_30 * ) ( V_14 + 1 ) ;
F_28 ( V_2 , V_31 , & V_21 ) ;
F_3 ( V_7 L_10
L_11 ,
F_29 ( & V_21 ) , V_21 . type ,
F_30 ( & V_21 ) ,
F_31 ( V_2 , V_31 ) ) ;
V_16 = (struct V_15 * ) ( V_31 + 1 ) ;
} else {
V_16 = (struct V_15 * ) ( V_14 + 1 ) ;
}
V_23 = ( unsigned long ) V_16 ;
V_22 = ( unsigned long ) V_14 + V_24 ;
while ( V_23 < V_22 ) {
V_16 = (struct V_15 * ) V_23 ;
type = F_32 ( V_2 , V_16 ) ;
V_26 = F_33 ( V_2 , V_16 ) ;
switch ( type ) {
case V_32 :
F_3 ( V_7 L_12
L_13 , V_26 ) ;
break;
case V_33 :
F_3 ( V_7 L_14
L_15 , V_26 ) ;
break;
case V_34 :
V_17 = (struct V_10 * ) ( & V_16 -> V_26 ) ;
F_13 ( V_2 , V_17 ) ;
break;
case V_35 :
V_19 = (struct V_18 * ) ( V_16 + 1 ) ;
F_3 ( V_7 L_16
L_17 ,
V_26 , F_34 ( V_2 , V_19 ) ) ;
break;
default:
F_24 () ;
}
V_23 += F_35 ( type ) ;
}
F_36 ( V_23 > V_22 ) ;
}
static void F_37 ( struct V_1 * V_2 , int V_12 )
{
struct V_36 * V_37 ;
V_37 = F_22 ( V_2 , V_12 , struct V_36 ) ;
F_3 ( L_18
L_19 ,
F_38 ( V_2 , V_37 ) ,
F_39 ( V_2 , V_37 ) ,
F_40 ( V_2 , V_37 ) ,
( unsigned long ) F_41 ( V_2 , V_37 ) ) ;
}
static void F_42 ( struct V_1 * V_38 , unsigned long V_26 ,
T_1 V_24 )
{
if ( ! F_43 ( V_24 , sizeof( T_2 ) ) ) {
F_44 ( L_20 ,
( unsigned long ) V_24 ) ;
return;
}
while ( V_24 ) {
T_3 V_39 ;
F_45 ( V_38 , & V_39 , V_26 , sizeof( V_39 ) ) ;
F_3 ( V_7 L_21 ,
( unsigned long long ) F_46 ( V_39 ) ) ;
V_24 -= sizeof( T_2 ) ;
V_26 += sizeof( T_2 ) ;
}
}
void F_47 ( struct V_40 * V_41 , struct V_1 * V_38 )
{
int V_6 ;
T_1 type , V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_10 * V_17 ;
struct V_18 * V_19 ;
struct V_55 * V_56 ;
struct V_57 V_21 ;
struct V_57 V_58 ;
if ( ! V_38 )
return;
V_42 = F_48 ( V_38 ) ;
F_49 ( V_41 -> V_59 , L_22 ,
F_50 ( V_38 ) , V_42 , F_51 ( V_41 , V_38 ) ) ;
for ( V_6 = 0 ; V_6 < V_42 ; V_6 ++ ) {
V_44 = F_52 ( V_38 , V_6 ) ;
F_53 ( V_38 , & V_21 , V_6 ) ;
type = F_54 ( & V_21 ) ;
F_3 ( V_7 L_23
L_24 ,
V_6 , V_21 . V_60 , type , V_21 . V_26 ,
F_55 ( V_38 , V_44 ) , F_56 ( V_38 , V_44 ) ) ;
switch ( type ) {
case V_61 :
V_50 = F_22 ( V_38 , V_6 , struct V_49 ) ;
F_3 ( V_7 L_25
L_26 ,
F_57 ( V_38 , V_50 ) ,
F_58 ( V_38 , V_50 ) ,
F_59 ( V_38 , V_50 ) ) ;
break;
case V_62 :
V_48 = F_22 ( V_38 , V_6 , struct V_47 ) ;
F_60 ( V_38 , V_48 , & V_58 ) ;
F_3 ( V_7 L_27 ,
V_58 . V_60 ,
F_61 ( V_38 , V_48 ) ) ;
break;
case V_63 :
V_46 = F_22 ( V_38 , V_6 , struct V_45 ) ;
F_3 ( V_7 L_28 ,
F_62 ( V_38 , V_46 ) ,
F_63 ( V_38 , V_46 ) ) ;
break;
case V_64 :
F_18 ( V_38 , V_6 ) ;
break;
case V_32 :
F_3 ( V_7 L_29 ) ;
break;
case V_33 :
F_3 ( V_7 L_30 ) ;
break;
case V_34 :
V_17 = F_22 ( V_38 , V_6 ,
struct V_10 ) ;
F_13 ( V_38 , V_17 ) ;
break;
case V_35 :
V_19 = F_22 ( V_38 , V_6 ,
struct V_18 ) ;
F_3 ( V_7 L_31 ,
F_34 ( V_38 , V_19 ) ) ;
break;
case V_65 :
V_54 = F_22 ( V_38 , V_6 ,
struct V_53 ) ;
if ( F_64 ( V_38 , V_54 ) ==
V_66 ) {
F_3 ( V_7 L_32
L_33 ,
F_65 ( V_38 , V_54 ) ) ;
break;
}
F_3 ( V_7 L_34
L_35 ,
F_66 ( V_38 , V_54 ) ,
F_67 ( V_38 , V_54 ) ) ;
F_3 ( V_7 L_36
L_37 ,
F_68 ( V_38 , V_54 ) ,
F_69 ( V_38 , V_54 ) ,
F_70 ( V_38 , V_54 ) ) ;
break;
case V_67 :
#ifdef F_20
F_37 ( V_38 , V_6 ) ;
#else
F_24 () ;
#endif
break;
case V_68 :
V_52 = F_22 ( V_38 , V_6 ,
struct V_51 ) ;
F_3 ( V_7 L_38 ,
F_71 ( V_38 , V_52 ) ) ;
break;
case V_69 :
F_1 ( V_38 , F_22 ( V_38 , V_6 ,
struct V_3 ) ) ;
break;
case V_70 :
F_9 ( V_38 , F_22 ( V_38 , V_6 ,
struct V_8 ) ) ;
break;
case V_71 :
V_56 = F_22 ( V_38 , V_6 ,
struct V_55 ) ;
F_3 ( V_7 L_39
L_40
L_41 ,
F_72 ( V_38 , V_56 ) ,
F_73 ( V_38 , V_56 ) ,
F_74 ( V_38 , V_56 ) ,
F_75 ( V_38 , V_56 ) ) ;
break;
case V_72 :
F_3 ( V_7 L_42 ) ;
break;
case V_73 :
F_3 ( V_7 L_43 ) ;
break;
case V_74 :
case V_75 :
F_42 ( V_38 , F_76 ( V_38 , V_6 ) ,
F_19 ( V_38 , V_6 ) ) ;
break;
} ;
}
}
void F_77 ( struct V_40 * V_41 , struct V_1 * V_76 )
{
int V_6 ; T_1 V_42 ;
struct V_57 V_21 ;
int V_77 ;
if ( ! V_76 )
return;
V_42 = F_48 ( V_76 ) ;
V_77 = F_78 ( V_76 ) ;
if ( V_77 == 0 ) {
F_47 ( V_41 , V_76 ) ;
return;
}
F_49 ( V_41 -> V_59 , L_44 ,
F_50 ( V_76 ) , V_77 , V_42 ,
( T_1 ) F_79 ( V_41 ) - V_42 ) ;
for ( V_6 = 0 ; V_6 < V_42 ; V_6 ++ ) {
F_80 ( V_76 , & V_21 , V_6 ) ;
F_3 ( V_7 L_45 ,
V_6 , V_21 . V_60 , V_21 . type , V_21 . V_26 ,
F_81 ( V_76 , V_6 ) ) ;
}
for ( V_6 = 0 ; V_6 < V_42 ; V_6 ++ ) {
struct V_1 * V_78 = F_82 ( V_41 ,
F_81 ( V_76 , V_6 ) ,
F_83 ( V_41 , V_77 - 1 ) ,
F_84 ( V_76 , V_6 ) ) ;
if ( F_85 ( V_78 ) &&
V_77 != 1 )
F_24 () ;
if ( F_78 ( V_78 ) !=
V_77 - 1 )
F_24 () ;
F_77 ( V_41 , V_78 ) ;
F_86 ( V_78 ) ;
}
}
