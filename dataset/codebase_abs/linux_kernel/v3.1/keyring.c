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
V_17 = F_12 ( V_5 -> V_19 . V_20 ,
F_13 ( & V_5 -> V_21 ) == 0 ) ;
if ( V_17 ) {
for ( V_18 = V_17 -> V_22 - 1 ; V_18 >= 0 ; V_18 -- )
F_14 ( V_17 -> V_23 [ V_18 ] ) ;
F_15 ( V_17 ) ;
}
}
static void F_16 ( const struct V_4 * V_5 , struct V_24 * V_25 )
{
struct V_16 * V_17 ;
if ( V_5 -> V_6 )
F_17 ( V_25 , V_5 -> V_6 ) ;
else
F_17 ( V_25 , L_1 ) ;
if ( F_18 ( V_5 ) ) {
F_19 () ;
V_17 = F_20 ( V_5 -> V_19 . V_20 ) ;
if ( V_17 )
F_21 ( V_25 , L_2 , V_17 -> V_22 , V_17 -> V_26 ) ;
else
F_17 ( V_25 , L_3 ) ;
F_22 () ;
}
}
static long F_23 ( const struct V_4 * V_5 ,
char T_2 * V_27 , T_1 V_28 )
{
struct V_16 * V_17 ;
struct V_4 * V_4 ;
T_1 V_29 , V_30 ;
int V_18 , V_14 ;
V_14 = 0 ;
V_17 = F_24 ( V_5 ) ;
if ( V_17 ) {
V_29 = V_17 -> V_22 * sizeof( V_31 ) ;
if ( V_27 && V_28 > 0 ) {
if ( V_28 > V_29 )
V_28 = V_29 ;
V_14 = - V_32 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_22 ; V_18 ++ ) {
V_4 = V_17 -> V_23 [ V_18 ] ;
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
F_14 ( V_5 ) ;
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
struct V_16 * V_47 ;
int V_48 ;
} V_49 [ V_50 ] ;
struct V_16 * V_47 ;
struct V_51 V_52 ;
unsigned long V_53 , V_54 ;
struct V_4 * V_5 , * V_4 ;
T_5 V_55 ;
long V_56 ;
int V_57 , V_48 ;
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
F_19 () ;
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
if ( V_54 & ( ( 1 << V_62 ) | ( 1 << V_67 ) ) ||
( V_5 -> V_64 && V_52 . V_65 >= V_5 -> V_64 ) )
goto V_63;
V_68:
if ( F_37 ( V_62 , & V_5 -> V_37 ) )
goto V_69;
V_47 = F_20 ( V_5 -> V_19 . V_20 ) ;
if ( ! V_47 )
goto V_69;
for ( V_48 = 0 ; V_48 < V_47 -> V_22 ; V_48 ++ ) {
V_4 = V_47 -> V_23 [ V_48 ] ;
V_54 = V_4 -> V_37 ;
if ( V_4 -> type != type )
continue;
if ( ! V_46 ) {
if ( V_54 & ( 1 << V_62 ) )
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
V_70:
for (; V_48 < V_47 -> V_22 ; V_48 ++ ) {
V_4 = V_47 -> V_23 [ V_48 ] ;
if ( V_4 -> type != & V_39 )
continue;
if ( V_57 >= V_50 )
continue;
if ( F_35 ( F_38 ( V_4 , V_53 ) ,
V_36 , V_58 ) < 0 )
continue;
V_49 [ V_57 ] . V_47 = V_47 ;
V_49 [ V_57 ] . V_48 = V_48 ;
V_57 ++ ;
V_5 = V_4 ;
goto V_68;
}
V_69:
if ( V_57 > 0 ) {
V_57 -- ;
V_47 = V_49 [ V_57 ] . V_47 ;
V_48 = V_49 [ V_57 ] . V_48 + 1 ;
goto V_70;
}
V_55 = F_30 ( V_56 ) ;
goto V_63;
V_61:
F_39 ( & V_4 -> V_21 ) ;
F_34 ( V_4 ) ;
V_55 = F_38 ( V_4 , V_53 ) ;
V_63:
F_22 () ;
error:
return V_55 ;
}
T_5 F_40 ( T_5 V_5 ,
struct V_44 * type ,
const char * V_6 )
{
if ( ! type -> V_45 )
return F_30 ( - V_71 ) ;
return F_31 ( V_5 , V_72 -> V_36 ,
type , V_6 , type -> V_45 , false ) ;
}
T_5 F_41 ( T_5 V_43 ,
const struct V_44 * V_73 ,
const char * V_6 ,
T_7 V_74 )
{
struct V_16 * V_17 ;
unsigned long V_53 ;
struct V_4 * V_5 , * V_4 ;
int V_18 ;
V_5 = F_32 ( V_43 ) ;
V_53 = F_33 ( V_43 ) ;
F_19 () ;
V_17 = F_20 ( V_5 -> V_19 . V_20 ) ;
if ( V_17 ) {
for ( V_18 = 0 ; V_18 < V_17 -> V_22 ; V_18 ++ ) {
V_4 = V_17 -> V_23 [ V_18 ] ;
if ( V_4 -> type == V_73 &&
( ! V_4 -> type -> V_45 ||
V_4 -> type -> V_45 ( V_4 , V_6 ) ) &&
F_42 ( F_38 ( V_4 , V_53 ) ,
V_74 ) == 0 &&
! F_37 ( V_62 , & V_4 -> V_37 )
)
goto V_61;
}
}
F_22 () ;
return F_30 ( - V_71 ) ;
V_61:
F_39 ( & V_4 -> V_21 ) ;
F_22 () ;
return F_38 ( V_4 , V_53 ) ;
}
struct V_4 * F_43 ( const char * V_75 , bool V_76 )
{
struct V_4 * V_5 ;
int V_2 ;
if ( ! V_75 )
return F_30 ( - V_15 ) ;
V_2 = F_1 ( V_75 ) ;
F_44 ( & V_7 ) ;
if ( V_8 [ V_2 ] . V_9 ) {
F_45 (keyring,
&keyring_name_hash[bucket],
type_data.link
) {
if ( V_5 -> V_77 -> V_78 != F_46 () )
continue;
if ( F_37 ( V_62 , & V_5 -> V_37 ) )
continue;
if ( strcmp ( V_5 -> V_6 , V_75 ) != 0 )
continue;
if ( ! V_76 &&
F_42 ( F_38 ( V_5 , 0 ) ,
V_58 ) < 0 )
continue;
if ( ! F_47 ( & V_5 -> V_21 ) )
continue;
goto V_79;
}
}
V_5 = F_30 ( - V_71 ) ;
V_79:
F_48 ( & V_7 ) ;
return V_5 ;
}
static int F_49 ( struct V_4 * V_80 , struct V_4 * V_81 )
{
struct {
struct V_16 * V_47 ;
int V_48 ;
} V_49 [ V_50 ] ;
struct V_16 * V_47 ;
struct V_4 * V_82 , * V_4 ;
int V_57 , V_48 , V_14 ;
F_19 () ;
V_14 = - V_83 ;
if ( V_80 == V_81 )
goto V_84;
V_82 = V_81 ;
V_57 = 0 ;
V_68:
if ( F_37 ( V_62 , & V_82 -> V_37 ) )
goto V_69;
V_47 = F_20 ( V_82 -> V_19 . V_20 ) ;
if ( ! V_47 )
goto V_69;
V_48 = 0 ;
V_70:
for (; V_48 < V_47 -> V_22 ; V_48 ++ ) {
V_4 = V_47 -> V_23 [ V_48 ] ;
if ( V_4 == V_80 )
goto V_84;
if ( V_4 -> type == & V_39 ) {
if ( V_57 >= V_50 )
goto V_85;
V_49 [ V_57 ] . V_47 = V_47 ;
V_49 [ V_57 ] . V_48 = V_48 ;
V_57 ++ ;
V_82 = V_4 ;
goto V_68;
}
}
V_69:
if ( V_57 > 0 ) {
V_57 -- ;
V_47 = V_49 [ V_57 ] . V_47 ;
V_48 = V_49 [ V_57 ] . V_48 + 1 ;
goto V_70;
}
V_14 = 0 ;
error:
F_22 () ;
return V_14 ;
V_85:
V_14 = - V_86 ;
goto error;
V_84:
V_14 = - V_83 ;
goto error;
}
static void F_50 ( struct V_87 * V_88 )
{
struct V_16 * V_17 =
F_51 ( V_88 , struct V_16 , V_88 ) ;
if ( V_17 -> V_89 != V_90 )
F_14 ( V_17 -> V_23 [ V_17 -> V_89 ] ) ;
F_15 ( V_17 ) ;
}
int F_52 ( struct V_4 * V_5 , const struct V_44 * type ,
const char * V_6 , unsigned long * V_91 )
__acquires( &keyring->sem
int F_53 ( struct V_4 * V_5 , struct V_4 * V_4 )
{
if ( V_4 -> type == & V_39 )
return F_49 ( V_5 , V_4 ) ;
return 0 ;
}
void F_54 ( struct V_4 * V_5 , struct V_4 * V_4 ,
unsigned long * V_91 )
{
struct V_16 * V_17 , * V_92 ;
V_92 = (struct V_16 * ) ( * V_91 & ~ V_93 ) ;
* V_91 = 0 ;
F_55 ( L_4 , V_5 -> V_33 , V_4 -> V_33 , V_92 ) ;
V_17 = F_56 ( V_5 -> V_19 . V_20 ,
F_57 ( & V_5 -> V_94 ) ) ;
F_39 ( & V_4 -> V_21 ) ;
if ( V_92 ) {
F_58 ( L_5 ,
V_92 -> V_89 , V_92 -> V_22 , V_92 -> V_26 ) ;
V_92 -> V_23 [ V_92 -> V_89 ] = V_4 ;
F_59 ( V_5 -> V_19 . V_20 , V_92 ) ;
if ( V_17 ) {
F_58 ( L_6 ,
V_17 -> V_89 , V_17 -> V_22 , V_17 -> V_26 ) ;
F_60 ( & V_17 -> V_88 , F_50 ) ;
}
} else {
V_17 -> V_23 [ V_17 -> V_22 ] = V_4 ;
F_61 () ;
V_17 -> V_22 ++ ;
}
}
void F_62 ( struct V_4 * V_5 , struct V_44 * type ,
unsigned long V_95 )
__releases( &keyring->sem
int F_63 ( struct V_4 * V_5 , struct V_4 * V_4 )
{
unsigned long V_95 ;
int V_14 ;
F_34 ( V_5 ) ;
F_34 ( V_4 ) ;
V_14 = F_52 ( V_5 , V_4 -> type , V_4 -> V_6 , & V_95 ) ;
if ( V_14 == 0 ) {
V_14 = F_53 ( V_5 , V_4 ) ;
if ( V_14 == 0 )
F_54 ( V_5 , V_4 , & V_95 ) ;
F_62 ( V_5 , V_4 -> type , V_95 ) ;
}
return V_14 ;
}
int F_64 ( struct V_4 * V_5 , struct V_4 * V_4 )
{
struct V_16 * V_17 , * V_92 ;
int V_18 , V_14 ;
F_34 ( V_5 ) ;
F_34 ( V_4 ) ;
V_14 = - V_59 ;
if ( V_5 -> type != & V_39 )
goto error;
F_65 ( & V_5 -> V_94 ) ;
V_17 = F_24 ( V_5 ) ;
if ( V_17 ) {
for ( V_18 = 0 ; V_18 < V_17 -> V_22 ; V_18 ++ )
if ( V_17 -> V_23 [ V_18 ] == V_4 )
goto V_96;
}
F_66 ( & V_5 -> V_94 ) ;
V_14 = - V_97 ;
goto error;
V_96:
V_92 = F_67 ( sizeof( * V_17 ) +
sizeof( struct V_4 * ) * V_17 -> V_26 ,
V_98 ) ;
if ( ! V_92 )
goto V_99;
V_92 -> V_26 = V_17 -> V_26 ;
V_92 -> V_22 = V_17 -> V_22 - 1 ;
if ( V_18 > 0 )
memcpy ( & V_92 -> V_23 [ 0 ] ,
& V_17 -> V_23 [ 0 ] ,
V_18 * sizeof( struct V_4 * ) ) ;
if ( V_18 < V_92 -> V_22 )
memcpy ( & V_92 -> V_23 [ V_18 ] ,
& V_17 -> V_23 [ V_18 + 1 ] ,
( V_92 -> V_22 - V_18 ) * sizeof( struct V_4 * ) ) ;
F_68 ( V_5 ,
V_5 -> V_13 - V_100 ) ;
F_59 ( V_5 -> V_19 . V_20 , V_92 ) ;
F_66 ( & V_5 -> V_94 ) ;
V_17 -> V_89 = V_18 ;
F_60 ( & V_17 -> V_88 , F_50 ) ;
V_14 = 0 ;
error:
return V_14 ;
V_99:
V_14 = - V_101 ;
F_66 ( & V_5 -> V_94 ) ;
goto error;
}
static void F_69 ( struct V_87 * V_88 )
{
struct V_16 * V_17 ;
int V_18 ;
V_17 = F_51 ( V_88 , struct V_16 , V_88 ) ;
for ( V_18 = V_17 -> V_22 - 1 ; V_18 >= 0 ; V_18 -- )
F_14 ( V_17 -> V_23 [ V_18 ] ) ;
F_15 ( V_17 ) ;
}
int F_70 ( struct V_4 * V_5 )
{
struct V_16 * V_17 ;
int V_14 ;
V_14 = - V_59 ;
if ( V_5 -> type == & V_39 ) {
F_65 ( & V_5 -> V_94 ) ;
V_17 = F_24 ( V_5 ) ;
if ( V_17 ) {
F_68 ( V_5 ,
sizeof( struct V_16 ) ) ;
F_59 ( V_5 -> V_19 . V_20 ,
NULL ) ;
}
F_66 ( & V_5 -> V_94 ) ;
if ( V_17 )
F_60 ( & V_17 -> V_88 , F_69 ) ;
V_14 = 0 ;
}
return V_14 ;
}
static void F_71 ( struct V_4 * V_5 )
{
struct V_16 * V_17 ;
V_17 = F_24 ( V_5 ) ;
F_68 ( V_5 , 0 ) ;
if ( V_17 ) {
F_59 ( V_5 -> V_19 . V_20 , NULL ) ;
F_60 ( & V_17 -> V_88 , F_69 ) ;
}
}
static bool F_72 ( struct V_4 * V_4 , T_8 V_102 )
{
return F_37 ( V_103 , & V_4 -> V_37 ) ||
( V_4 -> V_64 > 0 && V_4 -> V_64 <= V_102 ) ;
}
void F_73 ( struct V_4 * V_5 , T_8 V_102 )
{
struct V_16 * V_17 , * V_104 ;
struct V_4 * V_4 ;
int V_18 , V_105 , V_106 ;
F_55 ( L_7 , F_74 ( V_5 ) , V_5 -> V_6 ) ;
F_65 ( & V_5 -> V_94 ) ;
V_17 = F_24 ( V_5 ) ;
if ( ! V_17 )
goto V_107;
V_105 = 0 ;
for ( V_18 = V_17 -> V_22 - 1 ; V_18 >= 0 ; V_18 -- )
if ( ! F_72 ( V_17 -> V_23 [ V_18 ] , V_102 ) )
V_105 ++ ;
if ( V_105 == V_17 -> V_22 )
goto V_108;
V_106 = F_75 ( V_105 , 4 ) ;
V_104 = F_67 ( sizeof( struct V_16 ) + V_106 * sizeof( struct V_4 * ) ,
V_98 ) ;
if ( ! V_104 )
goto V_99;
V_104 -> V_26 = V_106 ;
V_104 -> V_22 = 0 ;
V_104 -> V_89 = 0 ;
V_105 = 0 ;
for ( V_18 = V_17 -> V_22 - 1 ; V_18 >= 0 ; V_18 -- ) {
V_4 = V_17 -> V_23 [ V_18 ] ;
if ( ! F_72 ( V_4 , V_102 ) ) {
if ( V_105 >= V_106 )
goto V_109;
V_104 -> V_23 [ V_105 ++ ] = F_76 ( V_4 ) ;
}
}
V_104 -> V_22 = V_105 ;
F_68 ( V_5 ,
sizeof( struct V_16 ) +
V_100 * V_105 ) ;
if ( V_105 == 0 ) {
F_59 ( V_5 -> V_19 . V_20 , NULL ) ;
F_15 ( V_104 ) ;
} else {
F_59 ( V_5 -> V_19 . V_20 , V_104 ) ;
}
F_66 ( & V_5 -> V_94 ) ;
F_60 ( & V_17 -> V_88 , F_69 ) ;
F_77 ( L_8 ) ;
return;
V_109:
V_104 -> V_22 = V_105 ;
F_69 ( & V_104 -> V_88 ) ;
F_66 ( & V_5 -> V_94 ) ;
F_77 ( L_9 ) ;
return;
V_108:
F_66 ( & V_5 -> V_94 ) ;
F_77 ( L_10 ) ;
return;
V_107:
F_66 ( & V_5 -> V_94 ) ;
F_77 ( L_11 ) ;
return;
V_99:
F_66 ( & V_5 -> V_94 ) ;
F_77 ( L_12 ) ;
}
