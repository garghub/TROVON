static inline unsigned F_1 ( const char * V_1 )
{
unsigned V_2 = 0 ;
for (; * V_1 ; V_1 ++ )
V_2 += ( unsigned char ) * V_1 ;
return V_2 & ( V_3 - 1 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
int V_2 ;
if ( V_5 -> V_6 ) {
V_2 = F_1 ( V_5 -> V_6 ) ;
F_3 ( & V_7 ) ;
if ( ! V_8 [ V_2 ] . V_9 )
F_4 ( & V_8 [ V_2 ] ) ;
F_5 ( & V_5 -> V_10 . V_11 ,
& V_8 [ V_2 ] ) ;
F_6 ( & V_7 ) ;
}
}
static int F_7 ( struct V_4 * V_5 ,
const void * V_12 , T_1 V_13 )
{
int V_14 ;
V_14 = - V_15 ;
if ( V_13 == 0 ) {
F_2 ( V_5 ) ;
V_14 = 0 ;
}
return V_14 ;
}
static int F_8 ( const struct V_4 * V_5 , const void * V_6 )
{
return V_5 -> V_6 &&
strcmp ( V_5 -> V_6 , V_6 ) == 0 ;
}
static void F_9 ( struct V_4 * V_5 )
{
struct V_16 * V_17 ;
int V_18 ;
if ( V_5 -> V_6 ) {
F_3 ( & V_7 ) ;
if ( V_5 -> V_10 . V_11 . V_9 != NULL &&
! F_10 ( & V_5 -> V_10 . V_11 ) )
F_11 ( & V_5 -> V_10 . V_11 ) ;
F_6 ( & V_7 ) ;
}
V_17 = F_12 ( V_5 -> V_19 . V_20 ) ;
if ( V_17 ) {
for ( V_18 = V_17 -> V_21 - 1 ; V_18 >= 0 ; V_18 -- )
F_13 ( F_12 ( V_17 -> V_22 [ V_18 ] ) ) ;
F_14 ( V_17 ) ;
}
}
static void F_15 ( const struct V_4 * V_5 , struct V_23 * V_24 )
{
struct V_16 * V_17 ;
if ( V_5 -> V_6 )
F_16 ( V_24 , V_5 -> V_6 ) ;
else
F_16 ( V_24 , L_1 ) ;
if ( F_17 ( V_5 ) ) {
F_18 () ;
V_17 = F_19 ( V_5 -> V_19 . V_20 ) ;
if ( V_17 )
F_20 ( V_24 , L_2 , V_17 -> V_21 , V_17 -> V_25 ) ;
else
F_16 ( V_24 , L_3 ) ;
F_21 () ;
}
}
static long F_22 ( const struct V_4 * V_5 ,
char T_2 * V_26 , T_1 V_27 )
{
struct V_16 * V_17 ;
struct V_4 * V_4 ;
T_1 V_28 , V_29 ;
int V_18 , V_14 ;
V_14 = 0 ;
V_17 = F_23 ( V_5 ) ;
if ( V_17 ) {
V_28 = V_17 -> V_21 * sizeof( V_30 ) ;
if ( V_26 && V_27 > 0 ) {
if ( V_27 > V_28 )
V_27 = V_28 ;
V_14 = - V_31 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_21 ; V_18 ++ ) {
V_4 = F_24 ( V_17 , V_18 ,
V_5 ) ;
V_29 = sizeof( V_30 ) ;
if ( V_29 > V_27 )
V_29 = V_27 ;
if ( F_25 ( V_26 ,
& V_4 -> V_32 ,
V_29 ) != 0 )
goto error;
V_27 -= V_29 ;
if ( V_27 == 0 )
break;
V_26 += V_29 ;
}
}
V_14 = V_28 ;
}
error:
return V_14 ;
}
struct V_4 * F_26 ( const char * V_6 , T_3 V_33 , T_4 V_34 ,
const struct V_35 * V_35 , unsigned long V_36 ,
struct V_4 * V_37 )
{
struct V_4 * V_5 ;
int V_14 ;
V_5 = F_27 ( & V_38 , V_6 ,
V_33 , V_34 , V_35 ,
( V_39 & ~ V_40 ) | V_41 ,
V_36 ) ;
if ( ! F_28 ( V_5 ) ) {
V_14 = F_29 ( V_5 , NULL , 0 , V_37 , NULL ) ;
if ( V_14 < 0 ) {
F_13 ( V_5 ) ;
V_5 = F_30 ( V_14 ) ;
}
}
return V_5 ;
}
T_5 F_31 ( T_5 V_42 ,
const struct V_35 * V_35 ,
struct V_43 * type ,
const void * V_6 ,
T_6 V_44 ,
bool V_45 )
{
struct {
struct V_4 * V_5 ;
struct V_16 * V_46 ;
int V_47 ;
} V_48 [ V_49 ] ;
struct V_16 * V_46 ;
struct V_50 V_51 ;
unsigned long V_52 , V_53 ;
struct V_4 * V_5 , * V_4 ;
T_5 V_54 ;
long V_55 ;
int V_56 , V_21 , V_47 ;
V_5 = F_32 ( V_42 ) ;
V_52 = F_33 ( V_42 ) ;
F_34 ( V_5 ) ;
V_55 = F_35 ( V_42 , V_35 , V_57 ) ;
if ( V_55 < 0 ) {
V_54 = F_30 ( V_55 ) ;
goto error;
}
V_54 = F_30 ( - V_58 ) ;
if ( V_5 -> type != & V_38 )
goto error;
F_18 () ;
V_51 = F_36 () ;
V_55 = - V_59 ;
V_56 = 0 ;
V_54 = F_30 ( - V_59 ) ;
V_53 = V_5 -> V_36 ;
if ( V_5 -> type == type && V_44 ( V_5 , V_6 ) ) {
V_4 = V_5 ;
if ( V_45 )
goto V_60;
if ( V_53 & ( 1 << V_61 ) )
goto V_62;
if ( V_4 -> V_63 && V_51 . V_64 >= V_4 -> V_63 )
goto V_62;
V_54 = F_30 ( V_4 -> V_10 . V_65 ) ;
if ( V_53 & ( 1 << V_66 ) )
goto V_62;
goto V_60;
}
V_54 = F_30 ( - V_59 ) ;
if ( V_53 & ( ( 1 << V_67 ) |
( 1 << V_61 ) |
( 1 << V_66 ) ) ||
( V_5 -> V_63 && V_51 . V_64 >= V_5 -> V_63 ) )
goto V_62;
V_68:
V_53 = V_5 -> V_36 ;
if ( V_53 & ( ( 1 << V_67 ) |
( 1 << V_61 ) ) )
goto V_69;
V_46 = F_19 ( V_5 -> V_19 . V_20 ) ;
if ( ! V_46 )
goto V_69;
V_21 = V_46 -> V_21 ;
F_37 () ;
for ( V_47 = 0 ; V_47 < V_21 ; V_47 ++ ) {
V_4 = F_19 ( V_46 -> V_22 [ V_47 ] ) ;
V_53 = V_4 -> V_36 ;
if ( V_4 -> type != type )
continue;
if ( ! V_45 ) {
if ( V_53 & ( ( 1 << V_67 ) |
( 1 << V_61 ) ) )
continue;
if ( V_4 -> V_63 && V_51 . V_64 >= V_4 -> V_63 )
continue;
}
if ( ! V_44 ( V_4 , V_6 ) )
continue;
if ( F_35 ( F_38 ( V_4 , V_52 ) ,
V_35 , V_57 ) < 0 )
continue;
if ( V_45 )
goto V_60;
if ( V_53 & ( 1 << V_66 ) ) {
V_55 = V_4 -> V_10 . V_65 ;
continue;
}
goto V_60;
}
V_47 = 0 ;
V_70:
V_21 = V_46 -> V_21 ;
F_37 () ;
for (; V_47 < V_21 ; V_47 ++ ) {
V_4 = F_19 ( V_46 -> V_22 [ V_47 ] ) ;
if ( V_4 -> type != & V_38 )
continue;
if ( V_56 >= V_49 )
continue;
if ( F_35 ( F_38 ( V_4 , V_52 ) ,
V_35 , V_57 ) < 0 )
continue;
V_48 [ V_56 ] . V_5 = V_5 ;
V_48 [ V_56 ] . V_46 = V_46 ;
V_48 [ V_56 ] . V_47 = V_47 ;
V_56 ++ ;
V_5 = V_4 ;
goto V_68;
}
V_69:
if ( V_56 > 0 ) {
V_56 -- ;
V_5 = V_48 [ V_56 ] . V_5 ;
V_46 = V_48 [ V_56 ] . V_46 ;
V_47 = V_48 [ V_56 ] . V_47 + 1 ;
goto V_70;
}
V_54 = F_30 ( V_55 ) ;
goto V_62;
V_60:
F_39 ( & V_4 -> V_71 ) ;
V_4 -> V_72 = V_51 . V_64 ;
V_5 -> V_72 = V_51 . V_64 ;
while ( V_56 > 0 )
V_48 [ -- V_56 ] . V_5 -> V_72 = V_51 . V_64 ;
F_34 ( V_4 ) ;
V_54 = F_38 ( V_4 , V_52 ) ;
V_62:
F_21 () ;
error:
return V_54 ;
}
T_5 F_40 ( T_5 V_5 ,
struct V_43 * type ,
const char * V_6 )
{
if ( ! type -> V_44 )
return F_30 ( - V_73 ) ;
return F_31 ( V_5 , V_74 -> V_35 ,
type , V_6 , type -> V_44 , false ) ;
}
T_5 F_41 ( T_5 V_42 ,
const struct V_43 * V_75 ,
const char * V_6 ,
T_7 V_76 )
{
struct V_16 * V_17 ;
unsigned long V_52 ;
struct V_4 * V_5 , * V_4 ;
int V_21 , V_18 ;
V_5 = F_32 ( V_42 ) ;
V_52 = F_33 ( V_42 ) ;
F_18 () ;
V_17 = F_19 ( V_5 -> V_19 . V_20 ) ;
if ( V_17 ) {
V_21 = V_17 -> V_21 ;
F_37 () ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
V_4 = F_19 ( V_17 -> V_22 [ V_18 ] ) ;
if ( V_4 -> type == V_75 &&
( ! V_4 -> type -> V_44 ||
V_4 -> type -> V_44 ( V_4 , V_6 ) ) &&
F_42 ( F_38 ( V_4 , V_52 ) ,
V_76 ) == 0 &&
! ( V_4 -> V_36 & ( ( 1 << V_67 ) |
( 1 << V_61 ) ) )
)
goto V_60;
}
}
F_21 () ;
return F_30 ( - V_73 ) ;
V_60:
F_39 ( & V_4 -> V_71 ) ;
V_5 -> V_72 = V_4 -> V_72 =
F_36 () . V_64 ;
F_21 () ;
return F_38 ( V_4 , V_52 ) ;
}
struct V_4 * F_43 ( const char * V_77 , bool V_78 )
{
struct V_4 * V_5 ;
int V_2 ;
if ( ! V_77 )
return F_30 ( - V_15 ) ;
V_2 = F_1 ( V_77 ) ;
F_44 ( & V_7 ) ;
if ( V_8 [ V_2 ] . V_9 ) {
F_45 (keyring,
&keyring_name_hash[bucket],
type_data.link
) {
if ( V_5 -> V_79 -> V_80 != F_46 () )
continue;
if ( F_47 ( V_61 , & V_5 -> V_36 ) )
continue;
if ( strcmp ( V_5 -> V_6 , V_77 ) != 0 )
continue;
if ( ! V_78 &&
F_42 ( F_38 ( V_5 , 0 ) ,
V_57 ) < 0 )
continue;
if ( ! F_48 ( & V_5 -> V_71 ) )
continue;
V_5 -> V_72 = F_36 () . V_64 ;
goto V_81;
}
}
V_5 = F_30 ( - V_73 ) ;
V_81:
F_49 ( & V_7 ) ;
return V_5 ;
}
static int F_50 ( struct V_4 * V_82 , struct V_4 * V_83 )
{
struct {
struct V_16 * V_46 ;
int V_47 ;
} V_48 [ V_49 ] ;
struct V_16 * V_46 ;
struct V_4 * V_84 , * V_4 ;
int V_56 , V_21 , V_47 , V_14 ;
F_18 () ;
V_14 = - V_85 ;
if ( V_82 == V_83 )
goto V_86;
V_84 = V_83 ;
V_56 = 0 ;
V_68:
if ( F_47 ( V_61 , & V_84 -> V_36 ) )
goto V_69;
V_46 = F_19 ( V_84 -> V_19 . V_20 ) ;
if ( ! V_46 )
goto V_69;
V_47 = 0 ;
V_70:
V_21 = V_46 -> V_21 ;
F_37 () ;
for (; V_47 < V_21 ; V_47 ++ ) {
V_4 = F_19 ( V_46 -> V_22 [ V_47 ] ) ;
if ( V_4 == V_82 )
goto V_86;
if ( V_4 -> type == & V_38 ) {
if ( V_56 >= V_49 )
goto V_87;
V_48 [ V_56 ] . V_46 = V_46 ;
V_48 [ V_56 ] . V_47 = V_47 ;
V_56 ++ ;
V_84 = V_4 ;
goto V_68;
}
}
V_69:
if ( V_56 > 0 ) {
V_56 -- ;
V_46 = V_48 [ V_56 ] . V_46 ;
V_47 = V_48 [ V_56 ] . V_47 + 1 ;
goto V_70;
}
V_14 = 0 ;
error:
F_21 () ;
return V_14 ;
V_87:
V_14 = - V_88 ;
goto error;
V_86:
V_14 = - V_85 ;
goto error;
}
static void F_51 ( struct V_89 * V_90 )
{
struct V_16 * V_17 =
F_52 ( V_90 , struct V_16 , V_90 ) ;
if ( V_17 -> V_91 != V_92 )
F_13 ( F_12 ( V_17 -> V_22 [ V_17 -> V_91 ] ) ) ;
F_14 ( V_17 ) ;
}
int F_53 ( struct V_4 * V_5 , const struct V_43 * type ,
const char * V_6 , unsigned long * V_93 )
__acquires( &keyring->sem
int F_54 ( struct V_4 * V_5 , struct V_4 * V_4 )
{
if ( V_4 -> type == & V_38 )
return F_50 ( V_5 , V_4 ) ;
return 0 ;
}
void F_55 ( struct V_4 * V_5 , struct V_4 * V_4 ,
unsigned long * V_93 )
{
struct V_16 * V_17 , * V_94 ;
struct V_4 * V_95 ;
V_94 = (struct V_16 * ) ( * V_93 & ~ V_96 ) ;
* V_93 = 0 ;
F_56 ( L_4 , V_5 -> V_32 , V_4 -> V_32 , V_94 ) ;
V_17 = F_23 ( V_5 ) ;
F_39 ( & V_4 -> V_71 ) ;
V_5 -> V_72 = V_4 -> V_72 =
F_36 () . V_64 ;
if ( V_94 ) {
F_57 ( L_5 ,
V_94 -> V_91 , V_94 -> V_21 , V_94 -> V_25 ) ;
F_58 ( V_94 -> V_22 [ V_94 -> V_91 ] , V_4 ) ;
F_59 ( V_5 -> V_19 . V_20 , V_94 ) ;
if ( V_17 ) {
F_57 ( L_6 ,
V_17 -> V_91 , V_17 -> V_21 , V_17 -> V_25 ) ;
F_60 ( & V_17 -> V_90 , F_51 ) ;
}
} else if ( V_17 -> V_91 < V_17 -> V_21 ) {
F_57 ( L_7 ,
V_17 -> V_91 , V_17 -> V_21 , V_17 -> V_25 ) ;
V_95 = F_61 (
V_17 -> V_22 [ V_17 -> V_91 ] ,
F_62 ( & V_5 -> V_97 ) ) ;
F_59 ( V_17 -> V_22 [ V_17 -> V_91 ] , V_4 ) ;
F_13 ( V_95 ) ;
} else {
F_57 ( L_8 ,
V_17 -> V_91 , V_17 -> V_21 , V_17 -> V_25 ) ;
F_58 ( V_17 -> V_22 [ V_17 -> V_91 ] , V_4 ) ;
F_63 () ;
V_17 -> V_21 ++ ;
}
}
void F_64 ( struct V_4 * V_5 , struct V_43 * type ,
unsigned long V_98 )
__releases( &keyring->sem
int F_65 ( struct V_4 * V_5 , struct V_4 * V_4 )
{
unsigned long V_98 ;
int V_14 ;
F_34 ( V_5 ) ;
F_34 ( V_4 ) ;
V_14 = F_53 ( V_5 , V_4 -> type , V_4 -> V_6 , & V_98 ) ;
if ( V_14 == 0 ) {
V_14 = F_54 ( V_5 , V_4 ) ;
if ( V_14 == 0 )
F_55 ( V_5 , V_4 , & V_98 ) ;
F_64 ( V_5 , V_4 -> type , V_98 ) ;
}
return V_14 ;
}
int F_66 ( struct V_4 * V_5 , struct V_4 * V_4 )
{
struct V_16 * V_17 , * V_94 ;
int V_18 , V_14 ;
F_34 ( V_5 ) ;
F_34 ( V_4 ) ;
V_14 = - V_58 ;
if ( V_5 -> type != & V_38 )
goto error;
F_67 ( & V_5 -> V_97 ) ;
V_17 = F_23 ( V_5 ) ;
if ( V_17 ) {
for ( V_18 = 0 ; V_18 < V_17 -> V_21 ; V_18 ++ )
if ( F_12 ( V_17 -> V_22 [ V_18 ] ) == V_4 )
goto V_99;
}
F_68 ( & V_5 -> V_97 ) ;
V_14 = - V_100 ;
goto error;
V_99:
V_94 = F_69 ( sizeof( * V_17 ) +
sizeof( struct V_4 * ) * V_17 -> V_25 ,
V_101 ) ;
if ( ! V_94 )
goto V_102;
V_94 -> V_25 = V_17 -> V_25 ;
V_94 -> V_21 = V_17 -> V_21 - 1 ;
if ( V_18 > 0 )
memcpy ( & V_94 -> V_22 [ 0 ] ,
& V_17 -> V_22 [ 0 ] ,
V_18 * sizeof( struct V_4 * ) ) ;
if ( V_18 < V_94 -> V_21 )
memcpy ( & V_94 -> V_22 [ V_18 ] ,
& V_17 -> V_22 [ V_18 + 1 ] ,
( V_94 -> V_21 - V_18 ) * sizeof( struct V_4 * ) ) ;
F_70 ( V_5 ,
V_5 -> V_13 - V_103 ) ;
F_59 ( V_5 -> V_19 . V_20 , V_94 ) ;
F_68 ( & V_5 -> V_97 ) ;
V_17 -> V_91 = V_18 ;
F_60 ( & V_17 -> V_90 , F_51 ) ;
V_14 = 0 ;
error:
return V_14 ;
V_102:
V_14 = - V_104 ;
F_68 ( & V_5 -> V_97 ) ;
goto error;
}
static void F_71 ( struct V_89 * V_90 )
{
struct V_16 * V_17 ;
int V_18 ;
V_17 = F_52 ( V_90 , struct V_16 , V_90 ) ;
for ( V_18 = V_17 -> V_21 - 1 ; V_18 >= 0 ; V_18 -- )
F_13 ( F_12 ( V_17 -> V_22 [ V_18 ] ) ) ;
F_14 ( V_17 ) ;
}
int F_72 ( struct V_4 * V_5 )
{
struct V_16 * V_17 ;
int V_14 ;
V_14 = - V_58 ;
if ( V_5 -> type == & V_38 ) {
F_67 ( & V_5 -> V_97 ) ;
V_17 = F_23 ( V_5 ) ;
if ( V_17 ) {
F_70 ( V_5 ,
sizeof( struct V_16 ) ) ;
F_59 ( V_5 -> V_19 . V_20 ,
NULL ) ;
}
F_68 ( & V_5 -> V_97 ) ;
if ( V_17 )
F_60 ( & V_17 -> V_90 , F_71 ) ;
V_14 = 0 ;
}
return V_14 ;
}
static void F_73 ( struct V_4 * V_5 )
{
struct V_16 * V_17 ;
V_17 = F_23 ( V_5 ) ;
F_70 ( V_5 , 0 ) ;
if ( V_17 ) {
F_59 ( V_5 -> V_19 . V_20 , NULL ) ;
F_60 ( & V_17 -> V_90 , F_71 ) ;
}
}
void F_74 ( struct V_4 * V_5 , T_8 V_105 )
{
struct V_16 * V_17 , * V_106 ;
struct V_4 * V_4 ;
int V_18 , V_107 , V_108 ;
F_56 ( L_9 , F_75 ( V_5 ) , V_5 -> V_6 ) ;
F_67 ( & V_5 -> V_97 ) ;
V_17 = F_23 ( V_5 ) ;
if ( ! V_17 )
goto V_109;
V_107 = 0 ;
for ( V_18 = V_17 -> V_21 - 1 ; V_18 >= 0 ; V_18 -- )
if ( ! F_76 ( F_24 ( V_17 , V_18 , V_5 ) ,
V_105 ) )
V_107 ++ ;
if ( V_107 == V_17 -> V_21 )
goto V_110;
V_108 = F_77 ( V_107 , 4 ) ;
V_106 = F_69 ( sizeof( struct V_16 ) + V_108 * sizeof( struct V_4 * ) ,
V_101 ) ;
if ( ! V_106 )
goto V_102;
V_106 -> V_25 = V_108 ;
V_106 -> V_21 = 0 ;
V_106 -> V_91 = 0 ;
V_107 = 0 ;
for ( V_18 = V_17 -> V_21 - 1 ; V_18 >= 0 ; V_18 -- ) {
V_4 = F_24 ( V_17 , V_18 , V_5 ) ;
if ( ! F_76 ( V_4 , V_105 ) ) {
if ( V_107 >= V_108 )
goto V_111;
F_58 ( V_106 -> V_22 [ V_107 ++ ] , F_78 ( V_4 ) ) ;
}
}
V_106 -> V_21 = V_107 ;
F_70 ( V_5 ,
sizeof( struct V_16 ) +
V_103 * V_107 ) ;
if ( V_107 == 0 ) {
F_59 ( V_5 -> V_19 . V_20 , NULL ) ;
F_14 ( V_106 ) ;
} else {
F_59 ( V_5 -> V_19 . V_20 , V_106 ) ;
}
F_68 ( & V_5 -> V_97 ) ;
F_60 ( & V_17 -> V_90 , F_71 ) ;
F_79 ( L_10 ) ;
return;
V_111:
V_106 -> V_21 = V_107 ;
F_71 ( & V_106 -> V_90 ) ;
F_68 ( & V_5 -> V_97 ) ;
F_79 ( L_11 ) ;
return;
V_110:
F_68 ( & V_5 -> V_97 ) ;
F_79 ( L_12 ) ;
return;
V_109:
F_68 ( & V_5 -> V_97 ) ;
F_79 ( L_13 ) ;
return;
V_102:
F_68 ( & V_5 -> V_97 ) ;
F_79 ( L_14 ) ;
}
