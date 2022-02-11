static void
F_1 ( union V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 * V_5 ;
char * V_6 ;
const char * V_7 ;
T_1 V_8 ;
if ( ! V_4 ) {
F_2
( L_1 ,
F_3 ( V_2 ) ) ;
return;
}
V_8 = V_4 -> V_9 ;
while ( V_8 ) {
V_5 = F_4 ( T_1 , V_2 , V_4 -> V_9 ) ;
V_6 = V_4 -> V_6 ;
switch ( V_4 -> V_10 ) {
case V_11 :
break;
case V_12 :
F_5 ( L_2 ,
F_3
( V_2 ) ) ;
break;
case V_13 :
F_2 ( L_3 , V_6 , * V_5 ) ;
break;
case V_14 :
F_2 ( L_4 , V_6 ,
F_6 ( V_5 ) ) ;
break;
case V_15 :
F_2 ( L_5 , V_6 ,
F_7 ( V_5 ) ) ;
break;
case V_16 :
F_2 ( L_6 , L_7 ,
F_8 ( F_9 ( V_5 ) ) ) ;
break;
case V_17 :
case V_18 :
F_10 ( V_6 ,
* F_11 ( void * , V_5 ) ) ;
break;
case V_19 :
F_12 ( V_2 -> string . V_20 ,
V_21 ) ;
F_2 ( L_8 ) ;
break;
case V_22 :
F_13 ( V_2 -> V_23 . V_20 ,
V_2 -> V_23 . V_24 ) ;
break;
case V_25 :
F_2 ( L_9 ) ;
F_14 ( V_2 , 0 , 0 ) ;
break;
case V_26 :
F_1 ( V_2 ,
V_27 ) ;
break;
case V_28 :
V_7 = F_15 ( V_2 ) ;
F_5 ( L_10 ,
F_11 ( char , V_7 ) ) ;
F_16 ( V_2 ) ;
break;
default:
F_2 ( L_11 ,
V_4 -> V_10 ) ;
return;
}
V_4 ++ ;
V_8 -- ;
}
}
void F_17 ( union V_1 * V_2 , T_2 V_29 )
{
T_2 V_24 ;
T_2 V_30 ;
F_18 (ex_dump_operand)
if ( ! F_19 ( V_31 , V_32 ) ) {
return;
}
if ( ! V_2 ) {
F_20 ( ( V_33 , L_12 ) ) ;
return;
}
if ( F_21 ( V_2 ) == V_34 ) {
F_20 ( ( V_33 , L_13 ,
V_2 ) ) ;
F_22 ( V_2 , V_31 ) ;
return;
}
if ( F_21 ( V_2 ) != V_35 ) {
F_20 ( ( V_33 ,
L_14 ,
V_2 ,
F_23 ( V_2 ) ) ) ;
F_13 ( V_2 , sizeof( union V_1 ) ) ;
return;
}
if ( V_29 > 0 ) {
F_20 ( ( V_33 , L_15 ,
V_29 , L_16 , V_29 , V_2 ) ) ;
} else {
F_20 ( ( V_33 , L_17 , V_2 ) ) ;
}
switch ( V_2 -> V_36 . type ) {
case V_37 :
F_2 ( L_18 ,
F_15 ( V_2 ) ) ;
switch ( V_2 -> V_38 . V_39 ) {
case V_40 :
F_2 ( L_8 ) ;
break;
case V_41 :
F_2 ( L_19 , V_2 -> V_38 . V_42 ) ;
break;
case V_43 :
F_2 ( L_20 ,
V_2 -> V_38 . V_44 ) ;
break;
case V_45 :
F_2 ( L_21 , V_2 -> V_38 . V_42 ,
F_24 ( ( (union
V_1
* )
V_2 ->
V_38 .
V_42 ) -> V_36 .
type ) ) ;
break;
case V_46 :
F_2 ( L_22 ,
V_2 -> V_38 . V_47 -> V_6 . V_48 ) ;
break;
case V_49 :
case V_50 :
F_2 ( L_23 , V_2 -> V_38 . V_44 ) ;
break;
default:
F_2 ( L_24 , V_2 -> V_38 . V_39 ) ;
break;
}
break;
case V_51 :
F_2 ( L_25 ,
V_2 -> V_23 . V_24 ,
V_2 -> V_23 . V_20 ) ;
if ( V_2 -> V_23 . V_20 ) {
V_24 = V_2 -> V_23 . V_24 ;
if ( V_24 > 128 ) {
V_24 = 128 ;
}
F_2
( L_26 ,
V_24 ) ;
F_13 ( V_2 -> V_23 . V_20 , V_24 ) ;
}
break;
case V_52 :
F_2 ( L_27 ,
F_8 ( V_2 -> integer . V_44 ) ) ;
break;
case V_53 :
F_2 ( L_28 ,
V_2 -> V_54 . V_8 ,
V_2 -> V_54 . V_55 ) ;
if ( V_2 -> V_54 . V_8 &&
V_2 -> V_54 . V_55 && V_56 > 1 ) {
for ( V_30 = 0 ; V_30 < V_2 -> V_54 . V_8 ;
V_30 ++ ) {
F_17 ( V_2 -> V_54 .
V_55 [ V_30 ] ,
V_29 + 1 ) ;
}
}
break;
case V_57 :
F_2 ( L_29 ,
F_25 ( V_2 -> V_58 .
V_59 ) ,
V_2 -> V_58 . V_59 ) ;
if ( ! ( V_2 -> V_58 . V_60 & V_61 ) ) {
F_2 ( L_8 ) ;
} else {
F_2 ( L_30 ,
F_26 ( V_2 -> V_58 .
V_62 ) ,
V_2 -> V_58 . V_24 ) ;
}
break;
case V_63 :
F_2 ( L_31 ,
V_2 -> string . V_24 ,
V_2 -> string . V_20 ) ;
F_12 ( V_2 -> string . V_20 , V_21 ) ;
F_2 ( L_8 ) ;
break;
case V_64 :
F_2 ( L_32 ) ;
break;
case V_65 :
F_2
( L_33
L_34 , V_2 -> V_66 . V_67 ,
V_2 -> V_66 . V_68 ,
V_2 -> V_66 . V_69 & V_70 ,
V_2 -> V_66 . V_69 & V_71 ,
V_2 -> V_66 . V_72 ,
V_2 -> V_66 . V_73 ) ;
F_17 ( V_2 -> V_66 . V_74 , V_29 + 1 ) ;
break;
case V_75 :
F_2 ( L_35 ) ;
break;
case V_76 :
F_2 ( L_36 ,
V_2 -> V_77 . V_67 ,
V_2 -> V_77 . V_72 ,
V_2 -> V_77 . V_73 ) ;
if ( ! V_2 -> V_77 . V_78 ) {
F_20 ( ( V_33 , L_37 ) ) ;
} else if ( ( V_2 -> V_77 . V_78 ) -> V_36 . type !=
V_51 ) {
F_2 ( L_38 ) ;
} else {
F_17 ( V_2 -> V_77 . V_78 ,
V_29 + 1 ) ;
}
break;
case V_79 :
F_2 ( L_39 ) ;
break;
case V_80 :
F_2 ( L_40 ,
V_2 -> V_81 . V_82 ,
V_2 -> V_81 . V_83 ,
V_2 -> V_81 . V_84 ) ;
break;
case V_85 :
F_2 ( L_41 ) ;
break;
case V_86 :
F_2 ( L_42 ) ;
break;
case V_87 :
F_2 ( L_43 ) ;
break;
case V_88 :
F_2 ( L_44 ) ;
break;
case V_89 :
F_2 ( L_45 ) ;
break;
default:
F_2 ( L_46 , V_2 -> V_36 . type ) ;
break;
}
return;
}
void
F_27 ( union V_1 * * V_90 ,
const char * V_91 , T_2 V_92 )
{
F_18 ( V_93 ) ;
if ( ! V_91 ) {
V_91 = L_47 ;
}
F_20 ( ( V_33 ,
L_48 ,
V_91 , V_92 ) ) ;
if ( V_92 == 0 ) {
V_92 = 1 ;
}
while ( V_92 ) {
F_17 ( * V_90 , 0 ) ;
V_90 ++ ;
V_92 -- ;
}
F_20 ( ( V_33 ,
L_49 , V_91 ) ) ;
return;
}
static void F_5 ( char * V_94 , char * V_44 )
{
F_2 ( L_50 , V_94 , V_44 ) ;
}
static void F_10 ( char * V_94 , void * V_44 )
{
F_2 ( L_51 , V_94 , V_44 ) ;
}
void F_28 ( struct V_95 * V_47 , T_2 V_60 )
{
F_29 () ;
if ( ! V_60 ) {
if ( ! F_19 ( V_96 , V_32 ) ) {
return;
}
}
F_2 ( L_52 , L_53 , F_30 ( V_47 ) ) ;
F_5 ( L_2 , F_24 ( V_47 -> type ) ) ;
F_10 ( L_54 ,
F_31 ( V_47 ) ) ;
F_10 ( L_55 , V_47 -> V_97 ) ;
F_1 ( F_11 ( union V_1 , V_47 ) ,
V_98 ) ;
}
static void F_16 ( union V_1 * V_2 )
{
struct V_99 V_100 ;
T_3 V_101 ;
V_100 . V_24 = V_102 ;
if ( V_2 -> V_38 . V_39 == V_46 ) {
F_2 ( L_56 , V_2 -> V_38 . V_47 ) ;
V_101 =
F_32 ( V_2 -> V_38 . V_47 ,
& V_100 ) ;
if ( F_33 ( V_101 ) ) {
F_2 ( L_57 ) ;
} else {
F_2 ( L_58 , ( char * ) V_100 . V_20 ) ;
F_34 ( V_100 . V_20 ) ;
}
} else if ( V_2 -> V_38 . V_42 ) {
if ( F_21 ( V_2 ) ==
V_35 ) {
F_2 ( L_59 ,
V_2 -> V_38 . V_42 ) ;
if ( V_2 -> V_38 . V_39 == V_43 ) {
F_2 ( L_60 ,
V_2 -> V_38 . V_44 ) ;
} else {
F_2 ( L_61 ,
V_2 -> V_38 . V_42 ,
F_24 ( ( (union
V_1
* )
V_2 ->
V_38 .
V_42 ) ->
V_36 .
type ) ) ;
}
} else {
F_2 ( L_62 ,
V_2 -> V_38 . V_42 ) ;
}
}
}
static void
F_14 ( union V_1 * V_2 ,
T_2 V_103 , T_2 V_30 )
{
T_2 V_104 ;
if ( V_103 > 0 ) {
for ( V_104 = 0 ; V_104 < V_103 ; V_104 ++ ) {
F_2 ( L_16 ) ;
}
F_2 ( L_63 , V_30 ) ;
}
F_2 ( L_17 , V_2 ) ;
if ( ! V_2 ) {
F_2 ( L_64 ) ;
return;
}
switch ( V_2 -> V_36 . type ) {
case V_52 :
F_2 ( L_65 ,
F_8 ( V_2 -> integer . V_44 ) ) ;
break;
case V_63 :
F_2 ( L_66 ) ;
F_12 ( V_2 -> string . V_20 , V_21 ) ;
F_2 ( L_8 ) ;
break;
case V_51 :
F_2 ( L_67 ,
V_2 -> V_23 . V_24 ) ;
if ( V_2 -> V_23 . V_24 ) {
F_35 ( F_11
( T_1 ,
V_2 -> V_23 . V_20 ) ,
V_2 -> V_23 . V_24 ,
V_105 , V_32 ) ;
} else {
F_2 ( L_8 ) ;
}
break;
case V_53 :
F_2 ( L_68 ,
V_2 -> V_54 . V_8 ) ;
for ( V_104 = 0 ; V_104 < V_2 -> V_54 . V_8 ; V_104 ++ ) {
F_14 ( V_2 -> V_54 . V_55 [ V_104 ] ,
V_103 + 1 , V_104 ) ;
}
break;
case V_37 :
F_2 ( L_69 ,
F_15 ( V_2 ) ,
V_2 -> V_38 . V_39 ) ;
F_16 ( V_2 ) ;
break;
default:
F_2 ( L_70 , V_2 -> V_36 . type ) ;
break;
}
}
void
F_36 ( union V_1 * V_2 , T_2 V_60 )
{
F_37 ( V_106 ) ;
if ( ! V_2 ) {
V_107 ;
}
if ( ! V_60 ) {
if ( ! F_19 ( V_96 , V_32 ) ) {
V_107 ;
}
}
if ( F_21 ( V_2 ) == V_34 ) {
F_28 ( (struct V_95 * )
V_2 , V_60 ) ;
F_2 ( L_71 ,
( (struct V_95 * ) V_2 ) ->
V_42 ) ;
F_36 ( ( (struct V_95 * )
V_2 ) -> V_42 , V_60 ) ;
V_107 ;
}
if ( F_21 ( V_2 ) != V_35 ) {
F_2
( L_72 ,
V_2 , F_23 ( V_2 ) ) ;
V_107 ;
}
if ( V_2 -> V_36 . type > V_108 ) {
V_107 ;
}
F_1 ( V_2 , V_109 ) ;
F_1 ( V_2 , V_110 [ V_2 -> V_36 . type ] ) ;
V_107 ;
}
