static T_1
F_1 ( union V_1 * V_2 ,
union V_3 * V_4 ,
T_2 * V_5 , T_3 * V_6 )
{
T_1 V_7 = V_8 ;
F_2 ( V_9 ) ;
* V_6 = 0 ;
if ( ! V_2 ) {
F_3 ( V_8 ) ;
}
F_4 ( V_4 , 0 , sizeof( union V_3 ) ) ;
V_4 -> type = V_2 -> V_10 . type ;
switch ( V_2 -> V_10 . type ) {
case V_11 :
V_4 -> string . V_12 = ( char * ) V_5 ;
V_4 -> string . V_13 = V_2 -> string . V_13 ;
* V_6 = F_5 ( ( T_3 )
V_2 ->
string .
V_13 + 1 ) ;
F_6 ( ( void * ) V_5 ,
( void * ) V_2 -> string . V_12 ,
( T_3 ) V_2 -> string . V_13 + 1 ) ;
break;
case V_14 :
V_4 -> V_15 . V_12 = V_5 ;
V_4 -> V_15 . V_13 = V_2 -> V_15 . V_13 ;
* V_6 =
F_5 ( V_2 -> string .
V_13 ) ;
F_6 ( ( void * ) V_5 ,
( void * ) V_2 -> V_15 . V_12 ,
V_2 -> V_15 . V_13 ) ;
break;
case V_16 :
V_4 -> integer . V_17 = V_2 -> integer . V_17 ;
break;
case V_18 :
switch ( V_2 -> V_19 . V_20 ) {
case V_21 :
V_4 -> V_19 . V_22 =
V_2 -> V_19 . V_23 ;
V_4 -> V_19 . V_24 =
F_7 ( V_2 -> V_19 . V_23 ) ;
break;
default:
F_3 ( V_25 ) ;
}
break;
case V_26 :
V_4 -> V_27 . V_28 =
V_2 -> V_27 . V_28 ;
V_4 -> V_27 . V_29 =
V_2 -> V_27 . V_30 ;
V_4 -> V_27 . V_31 =
V_2 -> V_27 . V_13 ;
break;
case V_32 :
V_4 -> V_33 . V_34 =
V_2 -> V_33 . V_34 ;
V_4 -> V_33 . V_35 =
V_2 -> V_33 . V_35 ;
break;
default:
F_8 ( ( V_36 ,
L_1 ,
F_9 ( V_2 -> V_10 .
type ) ) ) ;
F_3 ( V_37 ) ;
}
F_3 ( V_7 ) ;
}
static T_1
F_10 ( T_2 V_38 ,
union V_1 * V_39 ,
union V_40 * V_41 ,
void * V_42 )
{
T_1 V_7 = V_8 ;
struct V_43 * V_44 = (struct V_43 * ) V_42 ;
T_3 V_45 ;
T_4 V_46 ;
union V_3 * V_47 ;
F_11 () ;
V_46 = V_41 -> V_48 . V_49 ;
V_47 = (union V_3 * )
& ( (union V_3 * ) ( V_41 -> V_48 . V_50 ) ) -> V_51 .
V_52 [ V_46 ] ;
switch ( V_38 ) {
case V_53 :
V_7 = F_1 ( V_39 ,
V_47 ,
V_44 -> V_54 ,
& V_45 ) ;
if ( F_12 ( V_7 ) ) {
return ( V_7 ) ;
}
break;
case V_55 :
V_47 -> type = V_56 ;
V_47 -> V_51 . V_57 = V_39 -> V_51 . V_57 ;
V_47 -> V_51 . V_52 =
F_13 ( union V_3 , V_44 -> V_54 ) ;
V_41 -> V_48 . V_58 = V_47 ;
V_45 = F_5 ( ( T_3 )
V_47 ->
V_51 . V_57 *
sizeof( union
V_3 ) ) ;
break;
default:
return ( V_59 ) ;
}
V_44 -> V_54 += V_45 ;
V_44 -> V_13 += V_45 ;
return ( V_7 ) ;
}
static T_1
F_14 ( union V_1 * V_2 ,
T_2 * V_15 , T_3 * V_60 )
{
union V_3 * V_4 ;
T_1 V_7 ;
struct V_43 V_44 ;
F_2 ( V_61 ) ;
V_4 = F_13 ( union V_3 , V_15 ) ;
V_44 . V_13 = F_5 ( sizeof( union V_3 ) ) ;
V_44 . V_54 =
V_15 + F_5 ( sizeof( union V_3 ) ) ;
V_44 . V_45 = 0 ;
V_44 . V_62 = 1 ;
V_4 -> type = V_2 -> V_10 . type ;
V_4 -> V_51 . V_57 = V_2 -> V_51 . V_57 ;
V_4 -> V_51 . V_52 = F_13 ( union V_3 ,
V_44 . V_54 ) ;
V_44 . V_13 += ( T_3 ) V_4 -> V_51 . V_57 *
F_5 ( sizeof( union V_3 ) ) ;
V_44 . V_54 += V_4 -> V_51 . V_57 *
F_5 ( sizeof( union V_3 ) ) ;
V_7 = F_15 ( V_2 , V_4 ,
F_10 ,
& V_44 ) ;
* V_60 = V_44 . V_13 ;
F_3 ( V_7 ) ;
}
T_1
F_16 ( union V_1 * V_2 ,
struct V_63 * V_64 )
{
T_1 V_7 ;
F_2 ( V_65 ) ;
if ( V_2 -> V_10 . type == V_56 ) {
V_7 = F_14 ( V_2 ,
V_64 -> V_12 ,
& V_64 -> V_13 ) ;
} else {
V_7 = F_1 ( V_2 ,
F_13 ( union
V_3 ,
V_64 ->
V_12 ) ,
F_17 ( T_2 ,
V_64 ->
V_12 ,
F_5
( sizeof
( union
V_3 ) ) ) ,
& V_64 -> V_13 ) ;
V_64 -> V_13 += sizeof( union V_3 ) ;
}
F_3 ( V_7 ) ;
}
static T_1
F_18 ( union V_3 * V_4 ,
union V_1 * * V_66 )
{
union V_1 * V_2 ;
F_2 ( V_67 ) ;
switch ( V_4 -> type ) {
case V_11 :
case V_14 :
case V_16 :
case V_18 :
V_2 = F_19 ( ( T_2 )
V_4 ->
type ) ;
if ( ! V_2 ) {
F_3 ( V_68 ) ;
}
break;
case V_69 :
* V_66 = NULL ;
F_3 ( V_8 ) ;
default:
F_8 ( ( V_36 ,
L_2 ,
F_9 ( V_4 -> type ) ) ) ;
F_3 ( V_37 ) ;
}
switch ( V_4 -> type ) {
case V_11 :
V_2 -> string . V_12 =
F_20 ( ( T_3 )
V_4 -> string . V_13 + 1 ) ;
if ( ! V_2 -> string . V_12 ) {
goto V_70;
}
F_6 ( V_2 -> string . V_12 ,
V_4 -> string . V_12 ,
V_4 -> string . V_13 ) ;
V_2 -> string . V_13 = V_4 -> string . V_13 ;
break;
case V_14 :
V_2 -> V_15 . V_12 =
F_20 ( V_4 -> V_15 . V_13 ) ;
if ( ! V_2 -> V_15 . V_12 ) {
goto V_70;
}
F_6 ( V_2 -> V_15 . V_12 ,
V_4 -> V_15 . V_12 ,
V_4 -> V_15 . V_13 ) ;
V_2 -> V_15 . V_13 = V_4 -> V_15 . V_13 ;
V_2 -> V_15 . V_71 |= V_72 ;
break;
case V_16 :
V_2 -> integer . V_17 = V_4 -> integer . V_17 ;
break;
case V_18 :
V_2 -> V_19 . V_20 = V_73 ;
V_2 -> V_19 . V_74 =
V_4 -> V_19 . V_22 ;
break;
default:
break;
}
* V_66 = V_2 ;
F_3 ( V_8 ) ;
V_70:
F_21 ( V_2 ) ;
F_3 ( V_68 ) ;
}
static T_1
F_22 ( union V_3 * V_4 ,
union V_1 * * V_2 )
{
T_1 V_7 = V_8 ;
union V_1 * V_75 ;
union V_1 * * V_76 ;
T_4 V_77 ;
F_2 ( V_78 ) ;
V_75 =
F_23 ( V_4 -> V_51 . V_57 ) ;
if ( ! V_75 ) {
F_3 ( V_68 ) ;
}
V_76 = V_75 -> V_51 . V_52 ;
for ( V_77 = 0 ; V_77 < V_4 -> V_51 . V_57 ; V_77 ++ ) {
V_7 =
F_24 ( & V_4 -> V_51 .
V_52 [ V_77 ] ,
& V_76 [ V_77 ] ) ;
if ( F_12 ( V_7 ) ) {
V_75 -> V_51 . V_57 = V_77 ;
V_76 [ V_77 ] = NULL ;
F_21 ( V_75 ) ;
F_3 ( V_7 ) ;
}
}
V_75 -> V_51 . V_71 |= V_72 ;
* V_2 = V_75 ;
F_3 ( V_7 ) ;
}
T_1
F_24 ( union V_3 * V_4 ,
union V_1 * * V_2 )
{
T_1 V_7 ;
F_2 ( V_79 ) ;
if ( V_4 -> type == V_56 ) {
V_7 =
F_22 ( V_4 ,
V_2 ) ;
} else {
V_7 =
F_18 ( V_4 ,
V_2 ) ;
}
F_3 ( V_7 ) ;
}
static T_1
F_25 ( union V_1 * V_80 ,
union V_1 * V_81 )
{
T_5 V_82 ;
union V_1 * V_83 ;
T_1 V_7 ;
T_3 V_84 ;
V_82 = V_81 -> V_10 . V_82 ;
V_83 = V_81 -> V_10 . V_83 ;
V_84 = sizeof( union V_1 ) ;
if ( F_26 ( V_80 ) == V_85 ) {
V_84 = sizeof( struct V_86 ) ;
}
F_6 ( F_13 ( char , V_81 ) ,
F_13 ( char , V_80 ) , V_84 ) ;
V_81 -> V_10 . V_82 = V_82 ;
V_81 -> V_10 . V_83 = V_83 ;
V_81 -> V_10 . V_71 &= ~ V_87 ;
switch ( V_81 -> V_10 . type ) {
case V_14 :
if ( ( V_80 -> V_15 . V_12 ) &&
( V_80 -> V_15 . V_13 ) ) {
V_81 -> V_15 . V_12 =
F_27 ( V_80 -> V_15 . V_13 ) ;
if ( ! V_81 -> V_15 . V_12 ) {
return ( V_68 ) ;
}
F_6 ( V_81 -> V_15 . V_12 ,
V_80 -> V_15 . V_12 ,
V_80 -> V_15 . V_13 ) ;
}
break;
case V_11 :
if ( V_80 -> string . V_12 ) {
V_81 -> string . V_12 =
F_27 ( ( T_3 ) V_80 -> string .
V_13 + 1 ) ;
if ( ! V_81 -> string . V_12 ) {
return ( V_68 ) ;
}
F_6 ( V_81 -> string . V_12 ,
V_80 -> string . V_12 ,
( T_3 ) V_80 -> string . V_13 + 1 ) ;
}
break;
case V_18 :
if ( V_80 -> V_19 . V_20 == V_88 ) {
break;
}
F_28 ( V_80 -> V_19 . V_74 ) ;
break;
case V_89 :
if ( V_81 -> V_90 . V_91 ) {
F_28 ( V_81 -> V_90 . V_91 ) ;
}
break;
case V_92 :
V_7 = F_29 ( & V_81 -> V_93 . V_94 ) ;
if ( F_12 ( V_7 ) ) {
return ( V_7 ) ;
}
break;
case V_95 :
V_7 = F_30 ( V_96 , 0 ,
& V_81 -> V_97 .
V_98 ) ;
if ( F_12 ( V_7 ) ) {
return ( V_7 ) ;
}
break;
default:
break;
}
return ( V_8 ) ;
}
static T_1
F_31 ( T_2 V_38 ,
union V_1 * V_39 ,
union V_40 * V_41 ,
void * V_42 )
{
T_1 V_7 = V_8 ;
T_4 V_46 ;
union V_1 * * V_99 ;
union V_1 * V_47 ;
F_11 () ;
V_46 = V_41 -> V_48 . V_49 ;
V_99 = (union V_1 * * )
& V_41 -> V_48 . V_50 -> V_51 . V_52 [ V_46 ] ;
switch ( V_38 ) {
case V_53 :
if ( V_39 ) {
V_47 =
F_19 ( V_39 ->
V_10 . type ) ;
if ( ! V_47 ) {
return ( V_68 ) ;
}
V_7 =
F_25 ( V_39 ,
V_47 ) ;
if ( F_12 ( V_7 ) ) {
goto V_70;
}
* V_99 = V_47 ;
} else {
* V_99 = NULL ;
}
break;
case V_55 :
V_47 =
F_23 ( V_39 -> V_51 . V_57 ) ;
if ( ! V_47 ) {
return ( V_68 ) ;
}
V_47 -> V_10 . V_71 = V_39 -> V_10 . V_71 ;
V_41 -> V_48 . V_58 = V_47 ;
* V_99 = V_47 ;
break;
default:
return ( V_59 ) ;
}
return ( V_7 ) ;
V_70:
F_21 ( V_47 ) ;
return ( V_7 ) ;
}
static T_1
F_32 ( union V_1 * V_100 ,
union V_1 * V_101 ,
struct V_102 * V_103 )
{
T_1 V_7 = V_8 ;
F_2 ( V_104 ) ;
V_101 -> V_10 . type = V_100 -> V_10 . type ;
V_101 -> V_10 . V_71 = V_100 -> V_10 . V_71 ;
V_101 -> V_51 . V_57 = V_100 -> V_51 . V_57 ;
V_101 -> V_51 . V_52 = F_20 ( ( ( T_3 )
V_100 -> V_51 .
V_57 +
1 ) * sizeof( void * ) ) ;
if ( ! V_101 -> V_51 . V_52 ) {
F_8 ( ( V_36 , L_3 ) ) ;
F_3 ( V_68 ) ;
}
V_7 = F_15 ( V_100 , V_101 ,
F_31 ,
V_103 ) ;
if ( F_12 ( V_7 ) ) {
F_21 ( V_101 ) ;
}
F_3 ( V_7 ) ;
}
T_1
F_33 ( union V_1 * V_80 ,
union V_1 * * V_81 ,
struct V_102 * V_103 )
{
T_1 V_7 = V_8 ;
F_2 ( V_105 ) ;
* V_81 = F_19 ( V_80 -> V_10 . type ) ;
if ( ! * V_81 ) {
F_3 ( V_68 ) ;
}
if ( V_80 -> V_10 . type == V_56 ) {
V_7 =
F_32 ( V_80 , * V_81 ,
V_103 ) ;
} else {
V_7 = F_25 ( V_80 , * V_81 ) ;
}
F_3 ( V_7 ) ;
}
