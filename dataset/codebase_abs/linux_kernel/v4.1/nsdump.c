void F_1 ( T_1 V_1 , char * V_2 )
{
T_1 V_3 ;
F_2 ( V_4 ) ;
if ( ! F_3 ( V_5 , V_6 ) ) {
return;
}
F_4 ( ( V_7 , L_1 ) ) ;
while ( V_1 ) {
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
F_5 ( V_2 [ V_3 ] ) ?
F_6 ( L_2 , V_2 [ V_3 ] ) :
F_6 ( L_3 ) ;
}
V_2 += V_8 ;
V_1 -- ;
if ( V_1 ) {
F_6 ( L_4 ) ;
}
}
F_6 ( L_5 ) ;
}
void
F_7 ( T_2 V_9 , char * V_10 , T_1 V_11 , T_1 V_12 )
{
F_8 ( V_13 ) ;
if ( ! F_3 ( V_11 , V_12 ) ) {
V_14 ;
}
F_9 ( V_9 , V_10 ) ;
F_6 ( L_6 ) ;
V_14 ;
}
T_3
F_10 ( T_2 V_15 ,
T_1 V_11 , void * V_16 , void * * V_17 )
{
struct V_18 * V_19 = (struct V_18 * ) V_16 ;
struct V_20 * V_21 ;
union V_22 * V_23 = NULL ;
T_4 V_24 ;
T_4 type ;
T_1 V_25 ;
T_1 V_26 ;
T_1 V_3 ;
F_2 ( V_27 ) ;
if ( ! ( V_28 & V_19 -> V_29 ) ) {
return ( V_30 ) ;
}
if ( ! V_15 ) {
F_4 ( ( V_31 , L_7 ) ) ;
return ( V_30 ) ;
}
V_21 = F_11 ( V_15 ) ;
if ( ! V_21 ) {
F_4 ( ( V_31 , L_8 ,
V_15 ) ) ;
return ( V_30 ) ;
}
type = V_21 -> type ;
if ( ( V_19 -> V_32 != V_33 ) &&
( V_19 -> V_32 != V_21 -> V_32 ) ) {
return ( V_30 ) ;
}
if ( ! ( V_19 -> V_34 & V_35 ) ) {
F_6 ( L_9 , ( T_1 ) V_11 - 1 , ( int ) V_11 * 2 , L_10 ) ;
if ( type > V_36 ) {
F_12 ( ( V_37 ,
L_11 , type ) ) ;
}
F_6 ( L_12 , F_13 ( V_21 ) ) ;
}
F_6 ( L_13 ,
F_14 ( type ) , V_21 ,
V_21 -> V_32 ) ;
V_26 = V_28 ;
V_28 = 0 ;
V_23 = F_15 ( V_21 ) ;
V_28 = V_26 ;
if ( V_21 -> V_38 & V_39 ) {
F_6 ( L_14 ) ;
}
switch ( V_19 -> V_34 & V_40 ) {
case V_41 :
if ( ! V_23 ) {
switch ( type ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
F_6 ( L_15 ) ;
break;
default:
break;
}
F_6 ( L_6 ) ;
return ( V_30 ) ;
}
switch ( type ) {
case V_47 :
F_6 ( L_16 ,
V_23 -> V_48 . V_49 ,
V_23 -> V_48 . V_50 ,
F_16 ( V_23 -> V_48 .
V_51 ) ) ;
break;
case V_52 :
F_6 ( L_17 , V_23 ) ;
break;
case V_46 :
F_6 ( L_18 ,
( T_1 ) V_23 -> V_53 . V_54 ,
V_23 -> V_53 . V_55 ,
V_23 -> V_53 . V_56 ) ;
break;
case V_42 :
F_6 ( L_19 ,
F_16 ( V_23 -> integer .
V_57 ) ) ;
break;
case V_43 :
if ( V_23 -> V_58 . V_38 & V_59 ) {
F_6 ( L_20 ,
V_23 -> V_60 . V_61 ) ;
} else {
F_6 ( L_21 ) ;
}
break;
case V_44 :
if ( V_23 -> V_58 . V_38 & V_59 ) {
F_6 ( L_22 ,
V_23 -> V_62 . V_50 ) ;
if ( V_23 -> V_62 . V_50 > 0 ) {
F_6 ( L_23 ) ;
for ( V_3 = 0 ;
( V_3 < V_23 -> V_62 . V_50
&& V_3 < 12 ) ; V_3 ++ ) {
F_6 ( L_24 ,
V_23 -> V_62 .
V_63 [ V_3 ] ) ;
}
}
F_6 ( L_6 ) ;
} else {
F_6 ( L_21 ) ;
}
break;
case V_45 :
F_6 ( L_25 , V_23 -> string . V_50 ) ;
F_17 ( V_23 -> string . V_63 , 32 ) ;
F_6 ( L_6 ) ;
break;
case V_64 :
F_6 ( L_26 ,
F_18 ( V_23 -> V_65 .
V_66 ) ) ;
if ( V_23 -> V_65 . V_38 & V_59 ) {
F_6 ( L_27 ,
F_16 ( V_23 ->
V_65 .
V_51 ) ,
V_23 -> V_65 . V_50 ) ;
} else {
F_6
( L_28 ) ;
}
break;
case V_67 :
F_6 ( L_29 ,
F_19 ( V_23 ) ) ;
break;
case V_68 :
if ( V_23 -> V_69 . V_70 &&
V_23 -> V_69 . V_70 -> V_62 . V_71 ) {
F_6 ( L_30 ,
F_13 ( V_23 ->
V_69 .
V_70 ->
V_62 .
V_71 ) ) ;
}
break;
case V_72 :
F_6 ( L_31 ,
F_13 ( V_23 ->
V_73 .
V_74 -> V_65 .
V_71 ) ) ;
break;
case V_75 :
F_6 ( L_32 ,
F_13 ( V_23 ->
V_73 .
V_74 -> V_65 .
V_71 ) ,
F_13 ( V_23 ->
V_76 .
V_77 ->
V_73 .
V_71 ) ) ;
break;
case V_78 :
F_6 ( L_33 ,
F_13 ( V_23 ->
V_79 .
V_80 ->
V_73 . V_71 ) ,
F_13 ( V_23 ->
V_79 .
V_81 ->
V_73 .
V_71 ) ) ;
break;
case V_82 :
case V_83 :
F_6 ( L_34 ,
F_13 ( V_23 ) ,
V_23 ) ;
break;
default:
F_6 ( L_35 , V_23 ) ;
break;
}
switch ( type ) {
case V_68 :
case V_72 :
case V_75 :
case V_78 :
F_6 ( L_36 ,
( V_23 -> V_73 .
V_84 * 8 )
+
V_23 -> V_73 .
V_85 ,
V_23 -> V_73 . V_86 ,
V_23 -> V_73 .
V_87 ) ;
break;
default:
break;
}
break;
case V_88 :
F_6 ( L_37 , V_23 ) ;
if ( ! V_23 ) {
F_6 ( L_6 ) ;
return ( V_30 ) ;
}
F_6 ( L_38 , V_23 -> V_58 . V_89 ) ;
switch ( type ) {
case V_46 :
F_6 ( L_39 , V_23 -> V_53 . V_56 ,
V_23 -> V_53 . V_55 ) ;
break;
case V_42 :
F_6 ( L_40 ,
F_16 ( V_23 -> integer .
V_57 ) ) ;
break;
case V_45 :
F_6 ( L_41 , V_23 -> string . V_63 ,
V_23 -> string . V_50 ) ;
break;
case V_44 :
F_6 ( L_42 , V_23 -> V_62 . V_63 ,
V_23 -> V_62 . V_50 ) ;
break;
default:
F_6 ( L_6 ) ;
break;
}
break;
default:
F_6 ( L_6 ) ;
break;
}
if ( ! ( V_28 & V_90 ) ) {
return ( V_30 ) ;
}
V_26 = V_28 ;
V_28 = 0 ;
V_23 = F_15 ( V_21 ) ;
V_28 = V_26 ;
while ( V_23 ) {
V_24 = V_91 ;
F_6 ( L_43 , V_23 ) ;
switch ( F_20 ( V_23 ) ) {
case V_92 :
F_6 ( L_44 ) ;
V_25 = sizeof( struct V_20 ) ;
F_21 ( V_23 , V_25 ) ;
break;
case V_93 :
V_24 = V_23 -> V_58 . type ;
if ( V_24 > V_36 ) {
F_6
( L_45 ,
V_24 ) ;
V_25 = 32 ;
} else {
F_6
( L_46 ,
V_24 , F_14 ( V_24 ) ) ;
V_25 =
sizeof( union V_22 ) ;
}
F_21 ( V_23 , V_25 ) ;
break;
default:
break;
}
if ( F_20 ( V_23 ) !=
V_93 ) {
goto V_94;
}
switch ( V_24 ) {
case V_44 :
case V_45 :
V_25 = V_23 -> string . V_50 ;
V_23 = ( void * ) V_23 -> string . V_63 ;
F_6 ( L_47 ,
V_23 , V_25 ) ;
F_21 ( V_23 , V_25 ) ;
goto V_94;
case V_68 :
V_23 =
(union V_22 * ) V_23 -> V_69 .
V_70 ;
break;
case V_43 :
V_23 = ( void * ) V_23 -> V_60 . V_95 ;
break;
case V_46 :
V_23 = ( void * ) V_23 -> V_53 . V_56 ;
break;
case V_72 :
V_23 = ( void * ) V_23 -> V_96 . V_74 ;
break;
case V_75 :
V_23 = ( void * ) V_23 -> V_76 . V_74 ;
break;
case V_78 :
V_23 = ( void * ) V_23 -> V_79 . V_80 ;
break;
default:
goto V_94;
}
V_24 = V_91 ;
}
V_94:
F_6 ( L_6 ) ;
return ( V_30 ) ;
}
void
F_22 ( T_4 type ,
T_5 V_34 ,
T_1 V_97 ,
T_6 V_32 , T_2 V_98 )
{
struct V_18 V_19 ;
T_3 V_99 ;
F_23 () ;
V_99 = F_24 ( V_100 ) ;
if ( F_25 ( V_99 ) ) {
F_6 ( L_48 ) ;
return;
}
V_19 . V_29 = V_101 ;
V_19 . V_32 = V_32 ;
V_19 . V_34 = V_34 ;
( void ) F_26 ( type , V_98 , V_97 ,
V_102 |
V_103 ,
F_10 , NULL ,
( void * ) & V_19 , NULL ) ;
( void ) F_27 ( V_100 ) ;
}
static T_3
F_28 ( T_2 V_15 ,
T_1 V_11 , void * V_16 , void * * V_17 )
{
T_1 V_104 = * ( ( T_1 * ) V_16 ) ;
char * V_2 ;
struct V_20 * V_71 ;
int V_105 ;
if ( ! V_15 ) {
return ( V_30 ) ;
}
V_71 = F_11 ( V_15 ) ;
if ( ! V_71 ) {
return ( V_30 ) ;
}
V_2 = F_29 ( V_71 ) ;
V_105 = 1 ;
if ( V_11 <= V_104 ) {
V_105 = V_104 - V_11 + 1 ;
}
F_6 ( L_49 ,
V_11 , V_11 , L_10 , F_14 ( V_71 -> type ) ,
V_105 , L_10 ) ;
F_6 ( L_50 , & V_2 [ 1 ] ) ;
F_30 ( V_2 ) ;
return ( V_30 ) ;
}
static T_3
F_31 ( T_2 V_15 ,
T_1 V_11 , void * V_16 , void * * V_17 )
{
T_1 * V_104 = ( T_1 * ) V_16 ;
if ( V_11 > * V_104 ) {
* V_104 = V_11 ;
}
return ( V_30 ) ;
}
void
F_32 ( T_4 type ,
T_5 V_34 ,
T_1 V_97 ,
T_6 V_32 , T_2 V_98 )
{
T_3 V_99 ;
T_1 V_104 = 0 ;
F_23 () ;
V_99 = F_24 ( V_100 ) ;
if ( F_25 ( V_99 ) ) {
F_6 ( L_48 ) ;
return;
}
( void ) F_26 ( type , V_98 , V_97 ,
V_102 |
V_103 ,
F_31 , NULL ,
( void * ) & V_104 , NULL ) ;
( void ) F_26 ( type , V_98 , V_97 ,
V_102 |
V_103 ,
F_28 , NULL ,
( void * ) & V_104 , NULL ) ;
( void ) F_27 ( V_100 ) ;
}
void F_33 ( T_2 V_9 , T_1 V_29 )
{
struct V_18 V_19 ;
F_23 () ;
V_19 . V_29 = V_29 ;
V_19 . V_32 = V_33 ;
V_19 . V_34 = V_41 ;
( void ) F_10 ( V_9 , 1 , & V_19 , NULL ) ;
}
void F_34 ( T_2 V_106 , T_1 V_97 )
{
T_2 V_107 = V_106 ;
F_8 ( V_108 ) ;
if ( ! V_109 ) {
F_4 ( ( V_110 ,
L_51 ) ) ;
V_14 ;
}
if ( V_111 == V_106 ) {
V_107 = V_109 ;
F_4 ( ( V_110 , L_52 ) ) ;
}
F_22 ( V_112 , V_88 , V_97 ,
V_33 , V_107 ) ;
V_14 ;
}
