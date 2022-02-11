static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = F_2 ( V_2 , V_4 ) ;
int V_6 ;
F_3 ( L_1 ,
F_4 ( V_2 , V_4 ) , F_5 ( V_2 , V_4 ) ,
F_6 ( V_2 , V_4 ) , V_5 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
F_3 ( L_2 , V_6 ,
F_7 ( V_2 , V_4 , V_6 ) ,
F_8 ( V_2 , V_4 , V_6 ) ) ;
}
}
static void F_9 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
F_3 ( L_3 ,
F_10 ( V_2 , V_8 ) ,
F_11 ( V_2 , V_8 ) ,
F_12 ( V_2 , V_8 ) ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
F_3 ( L_4 ,
F_14 ( V_2 , V_10 ) ,
F_15 ( V_2 , V_10 ) ,
F_16 ( V_2 , V_10 ) ,
F_17 ( V_2 , V_10 ) ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_11 , int type )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_9 * V_16 ;
struct V_17 * V_18 ;
struct V_19 V_20 ;
unsigned long V_21 ;
unsigned long V_22 ;
T_1 V_23 = F_19 ( V_2 , V_11 ) ;
T_2 V_24 ;
T_2 V_25 ;
if ( V_23 < sizeof( * V_13 ) ) {
#ifdef F_20
struct V_26 * V_27 ;
F_21 ( V_23 != sizeof( * V_27 ) ) ;
V_27 = F_22 ( V_2 , V_11 , struct V_26 ) ;
F_3 ( L_5 ,
F_23 ( V_2 , V_27 ) ) ;
return;
#else
F_24 () ;
#endif
}
V_13 = F_22 ( V_2 , V_11 , struct V_12 ) ;
V_24 = F_25 ( V_2 , V_13 ) ;
F_3 ( L_6 ,
F_26 ( V_2 , V_13 ) , F_27 ( V_2 , V_13 ) ,
V_24 ) ;
if ( ( type == V_28 ) &&
V_24 & V_29 ) {
struct V_30 * V_31 ;
V_31 = (struct V_30 * ) ( V_13 + 1 ) ;
F_28 ( V_2 , V_31 , & V_20 ) ;
F_3 ( L_7 ,
F_29 ( & V_20 ) , V_20 . type ,
F_30 ( & V_20 ) ,
F_31 ( V_2 , V_31 ) ) ;
V_15 = (struct V_14 * ) ( V_31 + 1 ) ;
} else {
V_15 = (struct V_14 * ) ( V_13 + 1 ) ;
}
V_22 = ( unsigned long ) V_15 ;
V_21 = ( unsigned long ) V_13 + V_23 ;
while ( V_22 < V_21 ) {
V_15 = (struct V_14 * ) V_22 ;
type = F_32 ( V_2 , V_15 ) ;
V_25 = F_33 ( V_2 , V_15 ) ;
switch ( type ) {
case V_32 :
F_3 ( L_8 , V_25 ) ;
break;
case V_33 :
F_3 ( L_9 , V_25 ) ;
break;
case V_34 :
V_16 = (struct V_9 * ) ( & V_15 -> V_25 ) ;
F_13 ( V_2 , V_16 ) ;
break;
case V_35 :
V_18 = (struct V_17 * ) ( V_15 + 1 ) ;
F_3 ( L_10 ,
V_25 , F_34 ( V_2 , V_18 ) ) ;
break;
default:
F_24 () ;
}
V_22 += F_35 ( type ) ;
}
F_36 ( V_22 > V_21 ) ;
}
static void F_37 ( struct V_1 * V_2 , int V_11 )
{
struct V_36 * V_37 ;
V_37 = F_22 ( V_2 , V_11 , struct V_36 ) ;
F_38 ( L_11 ,
F_39 ( V_2 , V_37 ) ,
F_40 ( V_2 , V_37 ) ,
F_41 ( V_2 , V_37 ) ,
( unsigned long ) F_42 ( V_2 , V_37 ) ) ;
}
static void F_43 ( struct V_1 * V_38 , unsigned long V_25 ,
T_1 V_23 )
{
if ( ! F_44 ( V_23 , sizeof( T_2 ) ) ) {
F_45 ( L_12 ,
( unsigned long ) V_23 ) ;
return;
}
while ( V_23 ) {
T_3 V_39 ;
F_46 ( V_38 , & V_39 , V_25 , sizeof( V_39 ) ) ;
F_3 ( L_13 ,
( unsigned long long ) F_47 ( V_39 ) ) ;
V_23 -= sizeof( T_2 ) ;
V_25 += sizeof( T_2 ) ;
}
}
void F_48 ( struct V_40 * V_41 , struct V_1 * V_38 )
{
int V_6 ;
T_1 type , V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_9 * V_16 ;
struct V_17 * V_18 ;
struct V_55 * V_56 ;
struct V_57 V_20 ;
struct V_57 V_58 ;
if ( ! V_38 )
return;
V_42 = F_49 ( V_38 ) ;
F_50 ( V_41 , L_14 ,
F_51 ( V_38 ) , V_42 ,
F_52 ( V_41 , V_38 ) ) ;
for ( V_6 = 0 ; V_6 < V_42 ; V_6 ++ ) {
V_44 = F_53 ( V_6 ) ;
F_54 ( V_38 , & V_20 , V_6 ) ;
type = V_20 . type ;
F_3 ( L_15 ,
V_6 , V_20 . V_59 , type , V_20 . V_25 ,
F_55 ( V_38 , V_44 ) , F_56 ( V_38 , V_44 ) ) ;
switch ( type ) {
case V_60 :
V_50 = F_22 ( V_38 , V_6 , struct V_49 ) ;
F_3 ( L_16 ,
F_57 ( V_38 , V_50 ) ,
F_58 ( V_38 , V_50 ) ,
F_59 ( V_38 , V_50 ) ) ;
break;
case V_61 :
V_48 = F_22 ( V_38 , V_6 , struct V_47 ) ;
F_60 ( V_38 , V_48 , & V_58 ) ;
F_3 ( L_17 ,
V_58 . V_59 ,
F_61 ( V_38 , V_48 ) ) ;
break;
case V_62 :
V_46 = F_22 ( V_38 , V_6 , struct V_45 ) ;
F_3 ( L_18 ,
F_62 ( V_38 , V_46 ) ,
F_63 ( V_38 , V_46 ) ) ;
break;
case V_28 :
case V_63 :
F_18 ( V_38 , V_6 , type ) ;
break;
case V_32 :
F_3 ( L_19 ) ;
break;
case V_33 :
F_3 ( L_20 ) ;
break;
case V_34 :
V_16 = F_22 ( V_38 , V_6 ,
struct V_9 ) ;
F_13 ( V_38 , V_16 ) ;
break;
case V_35 :
V_18 = F_22 ( V_38 , V_6 ,
struct V_17 ) ;
F_3 ( L_21 ,
F_34 ( V_38 , V_18 ) ) ;
break;
case V_64 :
V_54 = F_22 ( V_38 , V_6 ,
struct V_53 ) ;
if ( F_64 ( V_38 , V_54 ) ==
V_65 ) {
F_3 ( L_22 ,
F_65 ( V_38 , V_6 , V_54 ) ) ;
break;
}
F_3 ( L_23 ,
F_66 ( V_38 , V_54 ) ,
F_67 ( V_38 , V_54 ) ) ;
F_3 ( L_24 ,
F_68 ( V_38 , V_54 ) ,
F_69 ( V_38 , V_54 ) ,
F_70 ( V_38 , V_54 ) ) ;
break;
case V_66 :
#ifdef F_20
F_37 ( V_38 , V_6 ) ;
#else
F_24 () ;
#endif
break;
case V_67 :
V_52 = F_22 ( V_38 , V_6 ,
struct V_51 ) ;
F_3 ( L_25 ,
F_71 ( V_38 , V_52 ) ) ;
break;
case V_68 :
F_1 ( V_38 , F_22 ( V_38 , V_6 ,
struct V_3 ) ) ;
break;
case V_69 :
F_9 ( V_38 , F_22 ( V_38 , V_6 ,
struct V_7 ) ) ;
break;
case V_70 :
V_56 = F_22 ( V_38 , V_6 ,
struct V_55 ) ;
F_3 ( L_26 ,
F_72 ( V_38 , V_56 ) ,
F_73 ( V_38 , V_56 ) ,
F_74 ( V_38 , V_56 ) ,
F_75 ( V_38 , V_56 ) ) ;
break;
case V_71 :
F_3 ( L_27 ,
V_20 . V_59 , V_20 . V_25 ) ;
switch ( V_20 . V_59 ) {
case V_72 :
F_3 ( L_28 ) ;
break;
default:
F_3 ( L_29 ) ;
}
break;
case V_73 :
F_3 ( L_30 ,
V_20 . V_59 , V_20 . V_25 ) ;
switch ( V_20 . V_59 ) {
case V_74 :
F_3 ( L_31 ) ;
break;
default:
F_3 ( L_32 ) ;
}
break;
case V_75 :
F_3 ( L_33 ) ;
break;
case V_76 :
case V_77 :
F_43 ( V_38 , F_76 ( V_38 , V_6 ) ,
F_19 ( V_38 , V_6 ) ) ;
break;
} ;
}
}
void F_77 ( struct V_40 * V_41 , struct V_1 * V_78 )
{
int V_6 ; T_1 V_42 ;
struct V_57 V_20 ;
int V_79 ;
if ( ! V_78 )
return;
V_42 = F_49 ( V_78 ) ;
V_79 = F_78 ( V_78 ) ;
if ( V_79 == 0 ) {
F_48 ( V_41 , V_78 ) ;
return;
}
F_50 ( V_41 ,
L_34 ,
F_51 ( V_78 ) , V_79 , V_42 ,
( T_1 ) F_79 ( V_41 ) - V_42 ) ;
for ( V_6 = 0 ; V_6 < V_42 ; V_6 ++ ) {
F_80 ( V_78 , & V_20 , V_6 ) ;
F_3 ( L_35 ,
V_6 , V_20 . V_59 , V_20 . type , V_20 . V_25 ,
F_81 ( V_78 , V_6 ) ) ;
}
for ( V_6 = 0 ; V_6 < V_42 ; V_6 ++ ) {
struct V_1 * V_80 = F_82 ( V_41 ,
F_81 ( V_78 , V_6 ) ,
F_83 ( V_78 , V_6 ) ) ;
if ( F_84 ( V_80 ) ) {
continue;
} else if ( ! F_85 ( V_80 ) ) {
F_86 ( V_80 ) ;
continue;
}
if ( F_87 ( V_80 ) &&
V_79 != 1 )
F_24 () ;
if ( F_78 ( V_80 ) !=
V_79 - 1 )
F_24 () ;
F_77 ( V_41 , V_80 ) ;
F_86 ( V_80 ) ;
}
}
