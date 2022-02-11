static void
F_1 ( union V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 * V_5 ;
char * V_6 ;
const char * V_7 ;
T_1 V_8 ;
union V_1 * V_9 ;
union V_1 * V_10 = NULL ;
union V_1 * V_11 ;
struct V_12 * V_13 ;
if ( ! V_4 ) {
F_2
( L_1 ,
F_3 ( V_2 ) ) ;
return;
}
V_8 = V_4 -> V_14 ;
while ( V_8 ) {
V_5 = F_4 ( T_1 , V_2 , V_4 -> V_14 ) ;
V_6 = V_4 -> V_6 ;
switch ( V_4 -> V_15 ) {
case V_16 :
break;
case V_17 :
F_2 ( L_2 , L_3 ,
V_2 -> V_18 . type ,
F_3 ( V_2 ) ) ;
break;
case V_19 :
F_2 ( L_4 , V_6 , * V_5 ) ;
break;
case V_20 :
F_2 ( L_5 , V_6 ,
F_5 ( V_5 ) ) ;
break;
case V_21 :
F_2 ( L_6 , V_6 ,
F_6 ( V_5 ) ) ;
break;
case V_22 :
F_2 ( L_7 , L_8 ,
F_7 ( F_8 ( V_5 ) ) ) ;
break;
case V_23 :
case V_24 :
F_9 ( V_6 ,
* F_10 ( void * , V_5 ) ) ;
break;
case V_25 :
F_11 ( V_2 -> string . V_26 ,
V_27 ) ;
F_2 ( L_9 ) ;
break;
case V_28 :
F_12 ( V_2 -> V_29 . V_26 ,
V_2 -> V_29 . V_30 ) ;
break;
case V_31 :
F_2 ( L_10 ) ;
F_13 ( V_2 , 0 , 0 ) ;
break;
case V_32 :
F_1 ( V_2 ,
V_33 ) ;
break;
case V_34 :
V_7 = F_14 ( V_2 ) ;
F_15 ( L_11 ,
F_10 ( char , V_7 ) ) ;
F_16 ( V_2 ) ;
break;
case V_35 :
V_9 = * F_10 ( void * , V_5 ) ;
V_11 = V_9 ;
F_2 ( L_12 , V_6 , V_11 ) ;
if ( V_11 ) {
F_2 ( L_13 ,
F_3
( V_11 ) , V_11 -> V_18 . type ) ;
while ( V_11 -> V_18 . V_36 ) {
if ( ( V_11 -> V_18 . type ==
V_37 ) && ! V_10 ) {
V_10 = V_11 ;
}
V_11 = V_11 -> V_18 . V_36 ;
F_2 ( L_14 , V_11 ,
F_3
( V_11 ) ,
V_11 -> V_18 . type ) ;
if ( ( V_11 == V_9 ) || ( V_11 == V_10 ) ) {
F_2
( L_15 ) ;
break;
}
}
}
F_2 ( L_9 ) ;
break;
case V_38 :
V_9 = * F_10 ( void * , V_5 ) ;
V_11 = V_9 ;
F_2 ( L_12 , V_6 , V_11 ) ;
if ( V_11 ) {
F_2 ( L_13 ,
F_3
( V_11 ) , V_11 -> V_18 . type ) ;
while ( V_11 -> V_39 . V_11 ) {
if ( ( V_11 -> V_18 . type ==
V_37 ) && ! V_10 ) {
V_10 = V_11 ;
}
V_11 = V_11 -> V_39 . V_11 ;
F_2 ( L_14 , V_11 ,
F_3
( V_11 ) ,
V_11 -> V_18 . type ) ;
if ( ( V_11 == V_9 ) || ( V_11 == V_10 ) ) {
F_2
( L_16 ) ;
break;
}
}
}
F_2 ( L_9 ) ;
break;
case V_40 :
V_9 = * F_10 ( void * , V_5 ) ;
V_11 = V_9 ;
F_2 ( L_12 , V_6 , V_11 ) ;
if ( V_11 ) {
F_2 ( L_13 ,
F_3
( V_11 ) , V_11 -> V_18 . type ) ;
while ( V_11 -> V_41 . V_11 ) {
if ( ( V_11 -> V_18 . type ==
V_37 ) && ! V_10 ) {
V_10 = V_11 ;
}
V_11 = V_11 -> V_41 . V_11 ;
F_2 ( L_14 , V_11 ,
F_3
( V_11 ) ,
V_11 -> V_18 . type ) ;
if ( ( V_11 == V_9 ) || ( V_11 == V_10 ) ) {
F_2
( L_17 ) ;
break;
}
}
}
F_2 ( L_9 ) ;
break;
case V_42 :
V_13 =
* F_10 ( struct V_12 * ,
V_5 ) ;
F_2 ( L_12 , V_6 , V_13 ) ;
if ( V_13 ) {
F_2 ( L_18 , V_13 -> V_6 . V_43 ) ;
}
F_2 ( L_9 ) ;
break;
default:
F_2 ( L_19 ,
V_4 -> V_15 ) ;
return;
}
V_4 ++ ;
V_8 -- ;
}
}
void F_17 ( union V_1 * V_2 , T_2 V_44 )
{
T_2 V_30 ;
T_2 V_45 ;
F_18 (ex_dump_operand)
if ( ! F_19 ( V_46 , V_47 ) ) {
return;
}
if ( ! V_2 ) {
F_20 ( ( V_48 , L_20 ) ) ;
return;
}
if ( F_21 ( V_2 ) == V_49 ) {
F_20 ( ( V_48 , L_21 ,
V_2 ) ) ;
F_22 ( V_2 , V_46 ) ;
return;
}
if ( F_21 ( V_2 ) != V_50 ) {
F_20 ( ( V_48 ,
L_22 ,
V_2 ,
F_23 ( V_2 ) ) ) ;
F_12 ( V_2 , sizeof( union V_1 ) ) ;
return;
}
if ( V_44 > 0 ) {
F_20 ( ( V_48 , L_23 ,
V_44 , L_24 , V_44 , V_2 ) ) ;
} else {
F_20 ( ( V_48 , L_25 , V_2 ) ) ;
}
switch ( V_2 -> V_18 . type ) {
case V_51 :
F_2 ( L_26 ,
F_14 ( V_2 ) ) ;
switch ( V_2 -> V_52 . V_53 ) {
case V_54 :
F_2 ( L_9 ) ;
break;
case V_55 :
F_2 ( L_27 , V_2 -> V_52 . V_56 ) ;
break;
case V_57 :
F_2 ( L_28 ,
V_2 -> V_52 . V_58 ) ;
break;
case V_59 :
F_2 ( L_29 , V_2 -> V_52 . V_56 ,
F_24 ( ( (union
V_1
* )
V_2 ->
V_52 .
V_56 ) -> V_18 .
type ) ) ;
break;
case V_60 :
F_2 ( L_30 ,
V_2 -> V_52 . V_13 -> V_6 . V_43 ) ;
break;
case V_61 :
case V_62 :
F_2 ( L_31 , V_2 -> V_52 . V_58 ) ;
break;
default:
F_2 ( L_32 , V_2 -> V_52 . V_53 ) ;
break;
}
break;
case V_63 :
F_2 ( L_33 ,
V_2 -> V_29 . V_30 ,
V_2 -> V_29 . V_26 ) ;
if ( V_2 -> V_29 . V_26 ) {
V_30 = V_2 -> V_29 . V_30 ;
if ( V_30 > 128 ) {
V_30 = 128 ;
}
F_2
( L_34 ,
V_30 ) ;
F_12 ( V_2 -> V_29 . V_26 , V_30 ) ;
}
break;
case V_64 :
F_2 ( L_35 ,
F_7 ( V_2 -> integer . V_58 ) ) ;
break;
case V_65 :
F_2 ( L_36 ,
V_2 -> V_66 . V_8 ,
V_2 -> V_66 . V_67 ) ;
if ( V_2 -> V_66 . V_8 &&
V_2 -> V_66 . V_67 && V_68 > 1 ) {
for ( V_45 = 0 ; V_45 < V_2 -> V_66 . V_8 ;
V_45 ++ ) {
F_17 ( V_2 -> V_66 .
V_67 [ V_45 ] ,
V_44 + 1 ) ;
}
}
break;
case V_69 :
F_2 ( L_37 ,
F_25 ( V_2 -> V_41 .
V_70 ) ,
V_2 -> V_41 . V_70 ) ;
if ( ! ( V_2 -> V_41 . V_71 & V_72 ) ) {
F_2 ( L_9 ) ;
} else {
F_2 ( L_38 ,
F_7 ( V_2 -> V_41 .
V_73 ) ,
V_2 -> V_41 . V_30 ) ;
}
break;
case V_74 :
F_2 ( L_39 ,
V_2 -> string . V_30 ,
V_2 -> string . V_26 ) ;
F_11 ( V_2 -> string . V_26 , V_27 ) ;
F_2 ( L_9 ) ;
break;
case V_75 :
F_2 ( L_40 ) ;
break;
case V_76 :
F_2
( L_41
L_42 , V_2 -> V_77 . V_78 ,
V_2 -> V_77 . V_79 ,
V_2 -> V_77 . V_80 & V_81 ,
V_2 -> V_77 . V_80 & V_82 ,
V_2 -> V_77 . V_83 ,
V_2 -> V_77 . V_84 ) ;
F_17 ( V_2 -> V_77 . V_85 , V_44 + 1 ) ;
break;
case V_86 :
F_2 ( L_43 ) ;
break;
case V_87 :
F_2 ( L_44 ,
V_2 -> V_88 . V_78 ,
V_2 -> V_88 . V_83 ,
V_2 -> V_88 . V_84 ) ;
if ( ! V_2 -> V_88 . V_89 ) {
F_20 ( ( V_48 , L_45 ) ) ;
} else if ( ( V_2 -> V_88 . V_89 ) -> V_18 . type !=
V_63 ) {
F_2 ( L_46 ) ;
} else {
F_17 ( V_2 -> V_88 . V_89 ,
V_44 + 1 ) ;
}
break;
case V_90 :
F_2 ( L_47 ) ;
break;
case V_91 :
F_2 ( L_48 ,
V_2 -> V_92 . V_93 ,
V_2 -> V_92 . V_94 ,
V_2 -> V_92 . V_95 ) ;
break;
case V_96 :
F_2 ( L_49 ) ;
break;
case V_97 :
F_2 ( L_50 ) ;
break;
case V_98 :
F_2 ( L_51 ) ;
break;
case V_99 :
F_2 ( L_52 ) ;
break;
case V_100 :
F_2 ( L_53 ) ;
break;
default:
F_2 ( L_54 , V_2 -> V_18 . type ) ;
break;
}
return;
}
void
F_26 ( union V_1 * * V_101 ,
const char * V_102 , T_2 V_103 )
{
F_18 ( V_104 ) ;
if ( ! V_102 ) {
V_102 = L_55 ;
}
F_20 ( ( V_48 ,
L_56 ,
V_102 , V_103 ) ) ;
if ( V_103 == 0 ) {
V_103 = 1 ;
}
while ( V_103 ) {
F_17 ( * V_101 , 0 ) ;
V_101 ++ ;
V_103 -- ;
}
F_20 ( ( V_48 ,
L_57 , V_102 ) ) ;
return;
}
static void F_15 ( char * V_105 , char * V_58 )
{
F_2 ( L_58 , V_105 , V_58 ) ;
}
static void F_9 ( char * V_105 , void * V_58 )
{
F_2 ( L_59 , V_105 , V_58 ) ;
}
void F_27 ( struct V_12 * V_13 , T_2 V_71 )
{
F_28 () ;
if ( ! V_71 ) {
if ( ! F_19 ( V_106 , V_47 ) ) {
return;
}
}
F_2 ( L_60 , L_61 , F_29 ( V_13 ) ) ;
F_2 ( L_2 , L_3 ,
V_13 -> type , F_24 ( V_13 -> type ) ) ;
F_1 ( F_10 ( union V_1 , V_13 ) ,
V_107 ) ;
}
static void F_16 ( union V_1 * V_2 )
{
struct V_108 V_109 ;
T_3 V_110 ;
V_109 . V_30 = V_111 ;
if ( V_2 -> V_52 . V_53 == V_60 ) {
F_2 ( L_62 , V_2 -> V_52 . V_13 ) ;
V_110 = F_30 ( V_2 -> V_52 . V_13 ,
& V_109 , TRUE ) ;
if ( F_31 ( V_110 ) ) {
F_2 ( L_63 ) ;
} else {
F_2 ( L_64 , ( char * ) V_109 . V_26 ) ;
F_32 ( V_109 . V_26 ) ;
}
} else if ( V_2 -> V_52 . V_56 ) {
if ( F_21 ( V_2 ) ==
V_50 ) {
F_2 ( L_65 , L_66 ,
V_2 -> V_52 . V_56 ) ;
if ( V_2 -> V_52 . V_53 == V_57 ) {
F_2 ( L_67 ,
V_2 -> V_52 . V_58 ) ;
} else {
F_2 ( L_68 ,
F_24 ( ( (union
V_1
* )
V_2 ->
V_52 .
V_56 ) ->
V_18 .
type ) ) ;
}
} else {
F_2 ( L_69 ,
V_2 -> V_52 . V_56 ) ;
}
}
}
static void
F_13 ( union V_1 * V_2 ,
T_2 V_112 , T_2 V_45 )
{
T_2 V_113 ;
if ( V_112 > 0 ) {
for ( V_113 = 0 ; V_113 < V_112 ; V_113 ++ ) {
F_2 ( L_24 ) ;
}
F_2 ( L_70 , V_45 ) ;
}
F_2 ( L_25 , V_2 ) ;
if ( ! V_2 ) {
F_2 ( L_71 ) ;
return;
}
switch ( V_2 -> V_18 . type ) {
case V_64 :
F_2 ( L_72 ,
F_7 ( V_2 -> integer . V_58 ) ) ;
break;
case V_74 :
F_2 ( L_73 ) ;
F_11 ( V_2 -> string . V_26 , V_27 ) ;
F_2 ( L_9 ) ;
break;
case V_63 :
F_2 ( L_74 ,
V_2 -> V_29 . V_30 ) ;
if ( V_2 -> V_29 . V_30 ) {
F_33 ( F_10
( T_1 ,
V_2 -> V_29 . V_26 ) ,
V_2 -> V_29 . V_30 ,
V_114 , V_47 ) ;
} else {
F_2 ( L_9 ) ;
}
break;
case V_65 :
F_2 ( L_75 ,
V_2 -> V_66 . V_8 ) ;
for ( V_113 = 0 ; V_113 < V_2 -> V_66 . V_8 ; V_113 ++ ) {
F_13 ( V_2 -> V_66 . V_67 [ V_113 ] ,
V_112 + 1 , V_113 ) ;
}
break;
case V_51 :
F_2 ( L_76 ,
F_14 ( V_2 ) ,
V_2 -> V_52 . V_53 ) ;
F_16 ( V_2 ) ;
break;
default:
F_2 ( L_77 , V_2 -> V_18 . type ) ;
break;
}
}
void
F_34 ( union V_1 * V_2 , T_2 V_71 )
{
F_35 ( V_115 ) ;
if ( ! V_2 ) {
V_116 ;
}
if ( ! V_71 ) {
if ( ! F_19 ( V_106 , V_47 ) ) {
V_116 ;
}
}
if ( F_21 ( V_2 ) == V_49 ) {
F_27 ( (struct V_12 * )
V_2 , V_71 ) ;
F_2 ( L_78 ,
( (struct V_12 * ) V_2 ) ->
V_56 ) ;
V_2 = ( (struct V_12 * ) V_2 ) -> V_56 ;
goto V_117;
}
if ( F_21 ( V_2 ) != V_50 ) {
F_2 ( L_79 ,
V_2 , F_23 ( V_2 ) ) ;
V_116 ;
}
if ( V_2 -> V_18 . type > V_118 ) {
F_2 ( L_80 ,
V_2 -> V_18 . type ) ;
V_116 ;
}
V_117:
F_1 ( V_2 , V_119 ) ;
F_1 ( V_2 , V_120 [ V_2 -> V_18 . type ] ) ;
if ( V_2 -> V_18 . type == V_69 ) {
V_2 = V_2 -> V_18 . V_36 ;
if ( V_2 -> V_18 . type > V_118 ) {
F_2
( L_81 ,
V_2 -> V_18 . type ) ;
V_116 ;
}
F_2 ( L_82 , V_2 ) ;
F_1 ( V_2 ,
V_120 [ V_2 -> V_18 . type ] ) ;
}
V_116 ;
}
