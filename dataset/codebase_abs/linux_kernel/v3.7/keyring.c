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
struct V_12 * V_13 )
{
int V_14 ;
V_14 = - V_15 ;
if ( V_13 -> V_16 == 0 ) {
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
struct V_17 * V_18 ;
int V_19 ;
if ( V_5 -> V_6 ) {
F_3 ( & V_7 ) ;
if ( V_5 -> V_10 . V_11 . V_9 != NULL &&
! F_10 ( & V_5 -> V_10 . V_11 ) )
F_11 ( & V_5 -> V_10 . V_11 ) ;
F_6 ( & V_7 ) ;
}
V_18 = F_12 ( V_5 -> V_20 . V_21 ) ;
if ( V_18 ) {
for ( V_19 = V_18 -> V_22 - 1 ; V_19 >= 0 ; V_19 -- )
F_13 ( F_12 ( V_18 -> V_23 [ V_19 ] ) ) ;
F_14 ( V_18 ) ;
}
}
static void F_15 ( const struct V_4 * V_5 , struct V_24 * V_25 )
{
struct V_17 * V_18 ;
if ( V_5 -> V_6 )
F_16 ( V_25 , V_5 -> V_6 ) ;
else
F_16 ( V_25 , L_1 ) ;
if ( F_17 ( V_5 ) ) {
F_18 () ;
V_18 = F_19 ( V_5 -> V_20 . V_21 ) ;
if ( V_18 )
F_20 ( V_25 , L_2 , V_18 -> V_22 , V_18 -> V_26 ) ;
else
F_16 ( V_25 , L_3 ) ;
F_21 () ;
}
}
static long F_22 ( const struct V_4 * V_5 ,
char T_1 * V_27 , T_2 V_28 )
{
struct V_17 * V_18 ;
struct V_4 * V_4 ;
T_2 V_29 , V_30 ;
int V_19 , V_14 ;
V_14 = 0 ;
V_18 = F_23 ( V_5 ) ;
if ( V_18 ) {
V_29 = V_18 -> V_22 * sizeof( V_31 ) ;
if ( V_27 && V_28 > 0 ) {
if ( V_28 > V_29 )
V_28 = V_29 ;
V_14 = - V_32 ;
for ( V_19 = 0 ; V_19 < V_18 -> V_22 ; V_19 ++ ) {
V_4 = F_24 ( V_18 , V_19 ,
V_5 ) ;
V_30 = sizeof( V_31 ) ;
if ( V_30 > V_28 )
V_30 = V_28 ;
if ( F_25 ( V_27 ,
& V_4 -> V_33 ,
V_30 ) != 0 )
goto error;
V_28 -= V_30 ;
if ( V_28 == 0 )
break;
V_27 += V_30 ;
}
}
V_14 = V_29 ;
}
error:
return V_14 ;
}
struct V_4 * F_26 ( const char * V_6 , T_3 V_34 , T_4 V_35 ,
const struct V_36 * V_36 , unsigned long V_37 ,
struct V_4 * V_38 )
{
struct V_4 * V_5 ;
int V_14 ;
V_5 = F_27 ( & V_39 , V_6 ,
V_34 , V_35 , V_36 ,
( V_40 & ~ V_41 ) | V_42 ,
V_37 ) ;
if ( ! F_28 ( V_5 ) ) {
V_14 = F_29 ( V_5 , NULL , 0 , V_38 , NULL ) ;
if ( V_14 < 0 ) {
F_13 ( V_5 ) ;
V_5 = F_30 ( V_14 ) ;
}
}
return V_5 ;
}
T_5 F_31 ( T_5 V_43 ,
const struct V_36 * V_36 ,
struct V_44 * type ,
const void * V_6 ,
T_6 V_45 ,
bool V_46 )
{
struct {
struct V_4 * V_5 ;
struct V_17 * V_47 ;
int V_48 ;
} V_49 [ V_50 ] ;
struct V_17 * V_47 ;
struct V_51 V_52 ;
unsigned long V_53 , V_54 ;
struct V_4 * V_5 , * V_4 ;
T_5 V_55 ;
long V_56 ;
int V_57 , V_22 , V_48 ;
V_5 = F_32 ( V_43 ) ;
V_53 = F_33 ( V_43 ) ;
F_34 ( V_5 ) ;
V_56 = F_35 ( V_43 , V_36 , V_58 ) ;
if ( V_56 < 0 ) {
V_55 = F_30 ( V_56 ) ;
goto error;
}
V_55 = F_30 ( - V_59 ) ;
if ( V_5 -> type != & V_39 )
goto error;
F_18 () ;
V_52 = F_36 () ;
V_56 = - V_60 ;
V_57 = 0 ;
V_55 = F_30 ( - V_60 ) ;
V_54 = V_5 -> V_37 ;
if ( V_5 -> type == type && V_45 ( V_5 , V_6 ) ) {
V_4 = V_5 ;
if ( V_46 )
goto V_61;
if ( V_54 & ( 1 << V_62 ) )
goto V_63;
if ( V_4 -> V_64 && V_52 . V_65 >= V_4 -> V_64 )
goto V_63;
V_55 = F_30 ( V_4 -> V_10 . V_66 ) ;
if ( V_54 & ( 1 << V_67 ) )
goto V_63;
goto V_61;
}
V_55 = F_30 ( - V_60 ) ;
if ( V_54 & ( ( 1 << V_68 ) |
( 1 << V_62 ) |
( 1 << V_67 ) ) ||
( V_5 -> V_64 && V_52 . V_65 >= V_5 -> V_64 ) )
goto V_63;
V_69:
V_54 = V_5 -> V_37 ;
if ( V_54 & ( ( 1 << V_68 ) |
( 1 << V_62 ) ) )
goto V_70;
V_47 = F_19 ( V_5 -> V_20 . V_21 ) ;
if ( ! V_47 )
goto V_70;
V_22 = V_47 -> V_22 ;
F_37 () ;
for ( V_48 = 0 ; V_48 < V_22 ; V_48 ++ ) {
V_4 = F_19 ( V_47 -> V_23 [ V_48 ] ) ;
V_54 = V_4 -> V_37 ;
if ( V_4 -> type != type )
continue;
if ( ! V_46 ) {
if ( V_54 & ( ( 1 << V_68 ) |
( 1 << V_62 ) ) )
continue;
if ( V_4 -> V_64 && V_52 . V_65 >= V_4 -> V_64 )
continue;
}
if ( ! V_45 ( V_4 , V_6 ) )
continue;
if ( F_35 ( F_38 ( V_4 , V_53 ) ,
V_36 , V_58 ) < 0 )
continue;
if ( V_46 )
goto V_61;
if ( V_54 & ( 1 << V_67 ) ) {
V_56 = V_4 -> V_10 . V_66 ;
continue;
}
goto V_61;
}
V_48 = 0 ;
V_71:
V_22 = V_47 -> V_22 ;
F_37 () ;
for (; V_48 < V_22 ; V_48 ++ ) {
V_4 = F_19 ( V_47 -> V_23 [ V_48 ] ) ;
if ( V_4 -> type != & V_39 )
continue;
if ( V_57 >= V_50 )
continue;
if ( F_35 ( F_38 ( V_4 , V_53 ) ,
V_36 , V_58 ) < 0 )
continue;
V_49 [ V_57 ] . V_5 = V_5 ;
V_49 [ V_57 ] . V_47 = V_47 ;
V_49 [ V_57 ] . V_48 = V_48 ;
V_57 ++ ;
V_5 = V_4 ;
goto V_69;
}
V_70:
if ( V_57 > 0 ) {
V_57 -- ;
V_5 = V_49 [ V_57 ] . V_5 ;
V_47 = V_49 [ V_57 ] . V_47 ;
V_48 = V_49 [ V_57 ] . V_48 + 1 ;
goto V_71;
}
V_55 = F_30 ( V_56 ) ;
goto V_63;
V_61:
F_39 ( & V_4 -> V_72 ) ;
V_4 -> V_73 = V_52 . V_65 ;
V_5 -> V_73 = V_52 . V_65 ;
while ( V_57 > 0 )
V_49 [ -- V_57 ] . V_5 -> V_73 = V_52 . V_65 ;
F_34 ( V_4 ) ;
V_55 = F_38 ( V_4 , V_53 ) ;
V_63:
F_21 () ;
error:
return V_55 ;
}
T_5 F_40 ( T_5 V_5 ,
struct V_44 * type ,
const char * V_6 )
{
if ( ! type -> V_45 )
return F_30 ( - V_74 ) ;
return F_31 ( V_5 , V_75 -> V_36 ,
type , V_6 , type -> V_45 , false ) ;
}
T_5 F_41 ( T_5 V_43 ,
const struct V_44 * V_76 ,
const char * V_6 ,
T_7 V_77 )
{
struct V_17 * V_18 ;
unsigned long V_53 ;
struct V_4 * V_5 , * V_4 ;
int V_22 , V_19 ;
V_5 = F_32 ( V_43 ) ;
V_53 = F_33 ( V_43 ) ;
F_18 () ;
V_18 = F_19 ( V_5 -> V_20 . V_21 ) ;
if ( V_18 ) {
V_22 = V_18 -> V_22 ;
F_37 () ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
V_4 = F_19 ( V_18 -> V_23 [ V_19 ] ) ;
if ( V_4 -> type == V_76 &&
( ! V_4 -> type -> V_45 ||
V_4 -> type -> V_45 ( V_4 , V_6 ) ) &&
F_42 ( F_38 ( V_4 , V_53 ) ,
V_77 ) == 0 &&
! ( V_4 -> V_37 & ( ( 1 << V_68 ) |
( 1 << V_62 ) ) )
)
goto V_61;
}
}
F_21 () ;
return F_30 ( - V_74 ) ;
V_61:
F_39 ( & V_4 -> V_72 ) ;
V_5 -> V_73 = V_4 -> V_73 =
F_36 () . V_65 ;
F_21 () ;
return F_38 ( V_4 , V_53 ) ;
}
struct V_4 * F_43 ( const char * V_78 , bool V_79 )
{
struct V_4 * V_5 ;
int V_2 ;
if ( ! V_78 )
return F_30 ( - V_15 ) ;
V_2 = F_1 ( V_78 ) ;
F_44 ( & V_7 ) ;
if ( V_8 [ V_2 ] . V_9 ) {
F_45 (keyring,
&keyring_name_hash[bucket],
type_data.link
) {
if ( ! F_46 ( F_47 () , V_5 -> V_80 -> V_34 ) )
continue;
if ( F_48 ( V_62 , & V_5 -> V_37 ) )
continue;
if ( strcmp ( V_5 -> V_6 , V_78 ) != 0 )
continue;
if ( ! V_79 &&
F_42 ( F_38 ( V_5 , 0 ) ,
V_58 ) < 0 )
continue;
if ( ! F_49 ( & V_5 -> V_72 ) )
continue;
V_5 -> V_73 = F_36 () . V_65 ;
goto V_81;
}
}
V_5 = F_30 ( - V_74 ) ;
V_81:
F_50 ( & V_7 ) ;
return V_5 ;
}
static int F_51 ( struct V_4 * V_82 , struct V_4 * V_83 )
{
struct {
struct V_17 * V_47 ;
int V_48 ;
} V_49 [ V_50 ] ;
struct V_17 * V_47 ;
struct V_4 * V_84 , * V_4 ;
int V_57 , V_22 , V_48 , V_14 ;
F_18 () ;
V_14 = - V_85 ;
if ( V_82 == V_83 )
goto V_86;
V_84 = V_83 ;
V_57 = 0 ;
V_69:
if ( F_48 ( V_62 , & V_84 -> V_37 ) )
goto V_70;
V_47 = F_19 ( V_84 -> V_20 . V_21 ) ;
if ( ! V_47 )
goto V_70;
V_48 = 0 ;
V_71:
V_22 = V_47 -> V_22 ;
F_37 () ;
for (; V_48 < V_22 ; V_48 ++ ) {
V_4 = F_19 ( V_47 -> V_23 [ V_48 ] ) ;
if ( V_4 == V_82 )
goto V_86;
if ( V_4 -> type == & V_39 ) {
if ( V_57 >= V_50 )
goto V_87;
V_49 [ V_57 ] . V_47 = V_47 ;
V_49 [ V_57 ] . V_48 = V_48 ;
V_57 ++ ;
V_84 = V_4 ;
goto V_69;
}
}
V_70:
if ( V_57 > 0 ) {
V_57 -- ;
V_47 = V_49 [ V_57 ] . V_47 ;
V_48 = V_49 [ V_57 ] . V_48 + 1 ;
goto V_71;
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
static void F_52 ( struct V_89 * V_90 )
{
struct V_17 * V_18 =
F_53 ( V_90 , struct V_17 , V_90 ) ;
if ( V_18 -> V_91 != V_92 )
F_13 ( F_12 ( V_18 -> V_23 [ V_18 -> V_91 ] ) ) ;
F_14 ( V_18 ) ;
}
int F_54 ( struct V_4 * V_5 , const struct V_44 * type ,
const char * V_6 , unsigned long * V_93 )
__acquires( &keyring->sem
int F_55 ( struct V_4 * V_5 , struct V_4 * V_4 )
{
if ( V_4 -> type == & V_39 )
return F_51 ( V_5 , V_4 ) ;
return 0 ;
}
void F_56 ( struct V_4 * V_5 , struct V_4 * V_4 ,
unsigned long * V_93 )
{
struct V_17 * V_18 , * V_94 ;
struct V_4 * V_95 ;
V_94 = (struct V_17 * ) ( * V_93 & ~ V_96 ) ;
* V_93 = 0 ;
F_57 ( L_4 , V_5 -> V_33 , V_4 -> V_33 , V_94 ) ;
V_18 = F_23 ( V_5 ) ;
F_39 ( & V_4 -> V_72 ) ;
V_5 -> V_73 = V_4 -> V_73 =
F_36 () . V_65 ;
if ( V_94 ) {
F_58 ( L_5 ,
V_94 -> V_91 , V_94 -> V_22 , V_94 -> V_26 ) ;
F_59 ( V_94 -> V_23 [ V_94 -> V_91 ] , V_4 ) ;
F_60 ( V_5 -> V_20 . V_21 , V_94 ) ;
if ( V_18 ) {
F_58 ( L_6 ,
V_18 -> V_91 , V_18 -> V_22 , V_18 -> V_26 ) ;
F_61 ( & V_18 -> V_90 , F_52 ) ;
}
} else if ( V_18 -> V_91 < V_18 -> V_22 ) {
F_58 ( L_7 ,
V_18 -> V_91 , V_18 -> V_22 , V_18 -> V_26 ) ;
V_95 = F_62 (
V_18 -> V_23 [ V_18 -> V_91 ] ,
F_63 ( & V_5 -> V_97 ) ) ;
F_60 ( V_18 -> V_23 [ V_18 -> V_91 ] , V_4 ) ;
F_13 ( V_95 ) ;
} else {
F_58 ( L_8 ,
V_18 -> V_91 , V_18 -> V_22 , V_18 -> V_26 ) ;
F_59 ( V_18 -> V_23 [ V_18 -> V_91 ] , V_4 ) ;
F_64 () ;
V_18 -> V_22 ++ ;
}
}
void F_65 ( struct V_4 * V_5 , struct V_44 * type ,
unsigned long V_98 )
__releases( &keyring->sem
int F_66 ( struct V_4 * V_5 , struct V_4 * V_4 )
{
unsigned long V_98 ;
int V_14 ;
F_34 ( V_5 ) ;
F_34 ( V_4 ) ;
V_14 = F_54 ( V_5 , V_4 -> type , V_4 -> V_6 , & V_98 ) ;
if ( V_14 == 0 ) {
V_14 = F_55 ( V_5 , V_4 ) ;
if ( V_14 == 0 )
F_56 ( V_5 , V_4 , & V_98 ) ;
F_65 ( V_5 , V_4 -> type , V_98 ) ;
}
return V_14 ;
}
int F_67 ( struct V_4 * V_5 , struct V_4 * V_4 )
{
struct V_17 * V_18 , * V_94 ;
int V_19 , V_14 ;
F_34 ( V_5 ) ;
F_34 ( V_4 ) ;
V_14 = - V_59 ;
if ( V_5 -> type != & V_39 )
goto error;
F_68 ( & V_5 -> V_97 ) ;
V_18 = F_23 ( V_5 ) ;
if ( V_18 ) {
for ( V_19 = 0 ; V_19 < V_18 -> V_22 ; V_19 ++ )
if ( F_12 ( V_18 -> V_23 [ V_19 ] ) == V_4 )
goto V_99;
}
F_69 ( & V_5 -> V_97 ) ;
V_14 = - V_100 ;
goto error;
V_99:
V_94 = F_70 ( sizeof( * V_18 ) +
sizeof( struct V_4 * ) * V_18 -> V_26 ,
V_101 ) ;
if ( ! V_94 )
goto V_102;
V_94 -> V_26 = V_18 -> V_26 ;
V_94 -> V_22 = V_18 -> V_22 - 1 ;
if ( V_19 > 0 )
memcpy ( & V_94 -> V_23 [ 0 ] ,
& V_18 -> V_23 [ 0 ] ,
V_19 * sizeof( struct V_4 * ) ) ;
if ( V_19 < V_94 -> V_22 )
memcpy ( & V_94 -> V_23 [ V_19 ] ,
& V_18 -> V_23 [ V_19 + 1 ] ,
( V_94 -> V_22 - V_19 ) * sizeof( struct V_4 * ) ) ;
F_71 ( V_5 ,
V_5 -> V_16 - V_103 ) ;
F_60 ( V_5 -> V_20 . V_21 , V_94 ) ;
F_69 ( & V_5 -> V_97 ) ;
V_18 -> V_91 = V_19 ;
F_61 ( & V_18 -> V_90 , F_52 ) ;
V_14 = 0 ;
error:
return V_14 ;
V_102:
V_14 = - V_104 ;
F_69 ( & V_5 -> V_97 ) ;
goto error;
}
static void F_72 ( struct V_89 * V_90 )
{
struct V_17 * V_18 ;
int V_19 ;
V_18 = F_53 ( V_90 , struct V_17 , V_90 ) ;
for ( V_19 = V_18 -> V_22 - 1 ; V_19 >= 0 ; V_19 -- )
F_13 ( F_12 ( V_18 -> V_23 [ V_19 ] ) ) ;
F_14 ( V_18 ) ;
}
int F_73 ( struct V_4 * V_5 )
{
struct V_17 * V_18 ;
int V_14 ;
V_14 = - V_59 ;
if ( V_5 -> type == & V_39 ) {
F_68 ( & V_5 -> V_97 ) ;
V_18 = F_23 ( V_5 ) ;
if ( V_18 ) {
F_71 ( V_5 ,
sizeof( struct V_17 ) ) ;
F_60 ( V_5 -> V_20 . V_21 ,
NULL ) ;
}
F_69 ( & V_5 -> V_97 ) ;
if ( V_18 )
F_61 ( & V_18 -> V_90 , F_72 ) ;
V_14 = 0 ;
}
return V_14 ;
}
static void F_74 ( struct V_4 * V_5 )
{
struct V_17 * V_18 ;
V_18 = F_23 ( V_5 ) ;
F_71 ( V_5 , 0 ) ;
if ( V_18 ) {
F_60 ( V_5 -> V_20 . V_21 , NULL ) ;
F_61 ( & V_18 -> V_90 , F_72 ) ;
}
}
void F_75 ( struct V_4 * V_5 , T_8 V_105 )
{
struct V_17 * V_18 , * V_106 ;
struct V_4 * V_4 ;
int V_19 , V_107 , V_108 ;
F_57 ( L_9 , F_76 ( V_5 ) , V_5 -> V_6 ) ;
F_68 ( & V_5 -> V_97 ) ;
V_18 = F_23 ( V_5 ) ;
if ( ! V_18 )
goto V_109;
V_107 = 0 ;
for ( V_19 = V_18 -> V_22 - 1 ; V_19 >= 0 ; V_19 -- )
if ( ! F_77 ( F_24 ( V_18 , V_19 , V_5 ) ,
V_105 ) )
V_107 ++ ;
if ( V_107 == V_18 -> V_22 )
goto V_110;
V_108 = F_78 ( V_107 , 4 ) ;
V_106 = F_70 ( sizeof( struct V_17 ) + V_108 * sizeof( struct V_4 * ) ,
V_101 ) ;
if ( ! V_106 )
goto V_102;
V_106 -> V_26 = V_108 ;
V_106 -> V_22 = 0 ;
V_106 -> V_91 = 0 ;
V_107 = 0 ;
for ( V_19 = V_18 -> V_22 - 1 ; V_19 >= 0 ; V_19 -- ) {
V_4 = F_24 ( V_18 , V_19 , V_5 ) ;
if ( ! F_77 ( V_4 , V_105 ) ) {
if ( V_107 >= V_108 )
goto V_111;
F_59 ( V_106 -> V_23 [ V_107 ++ ] , F_79 ( V_4 ) ) ;
}
}
V_106 -> V_22 = V_107 ;
F_71 ( V_5 ,
sizeof( struct V_17 ) +
V_103 * V_107 ) ;
if ( V_107 == 0 ) {
F_60 ( V_5 -> V_20 . V_21 , NULL ) ;
F_14 ( V_106 ) ;
} else {
F_60 ( V_5 -> V_20 . V_21 , V_106 ) ;
}
F_69 ( & V_5 -> V_97 ) ;
F_61 ( & V_18 -> V_90 , F_72 ) ;
F_80 ( L_10 ) ;
return;
V_111:
V_106 -> V_22 = V_107 ;
F_72 ( & V_106 -> V_90 ) ;
F_69 ( & V_5 -> V_97 ) ;
F_80 ( L_11 ) ;
return;
V_110:
F_69 ( & V_5 -> V_97 ) ;
F_80 ( L_12 ) ;
return;
V_109:
F_69 ( & V_5 -> V_97 ) ;
F_80 ( L_13 ) ;
return;
V_102:
F_69 ( & V_5 -> V_97 ) ;
F_80 ( L_14 ) ;
}
