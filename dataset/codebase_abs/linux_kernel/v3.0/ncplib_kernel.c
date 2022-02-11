static inline void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == 0 ) {
F_2 ( L_1 ) ;
}
}
static void F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
F_1 ( V_2 ) ;
* ( T_1 * ) ( & ( V_2 -> V_5 [ V_2 -> V_6 ] ) ) = V_4 ;
V_2 -> V_6 += 1 ;
return;
}
static void F_4 ( struct V_1 * V_2 , T_2 V_4 )
{
F_1 ( V_2 ) ;
F_5 ( V_4 , ( T_2 * ) ( & ( V_2 -> V_5 [ V_2 -> V_6 ] ) ) ) ;
V_2 -> V_6 += 2 ;
return;
}
static void F_6 ( struct V_1 * V_2 , T_3 V_4 )
{
F_1 ( V_2 ) ;
F_5 ( F_7 ( V_4 ) , ( V_7 * ) ( & ( V_2 -> V_5 [ V_2 -> V_6 ] ) ) ) ;
V_2 -> V_6 += 2 ;
}
static void F_8 ( struct V_1 * V_2 , T_4 V_4 )
{
F_1 ( V_2 ) ;
F_5 ( V_4 , ( T_4 * ) ( & ( V_2 -> V_5 [ V_2 -> V_6 ] ) ) ) ;
V_2 -> V_6 += 4 ;
return;
}
static void F_9 ( struct V_1 * V_2 , T_5 V_4 )
{
F_1 ( V_2 ) ;
F_5 ( F_10 ( V_4 ) , ( V_8 * ) ( & ( V_2 -> V_5 [ V_2 -> V_6 ] ) ) ) ;
V_2 -> V_6 += 4 ;
}
static inline void F_11 ( struct V_1 * V_2 , T_5 V_4 ) {
F_8 ( V_2 , F_12 ( V_4 ) ) ;
}
static void F_13 ( struct V_1 * V_2 , const void * V_9 , int V_10 )
{
F_1 ( V_2 ) ;
memcpy ( & ( V_2 -> V_5 [ V_2 -> V_6 ] ) , V_9 , V_10 ) ;
V_2 -> V_6 += V_10 ;
return;
}
static void F_14 ( struct V_1 * V_2 , const char * V_11 )
{
int V_12 = strlen ( V_11 ) ;
F_1 ( V_2 ) ;
if ( V_12 > 255 ) {
F_2 ( L_2 , V_11 ) ;
V_12 = 255 ;
}
F_3 ( V_2 , V_12 ) ;
F_13 ( V_2 , V_11 , V_12 ) ;
return;
}
static inline void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
V_2 -> V_6 = sizeof( struct V_13 ) ;
V_2 -> V_14 = 0 ;
}
static inline void F_17 ( struct V_1 * V_2 , int V_15 )
{
F_16 ( V_2 ) ;
V_2 -> V_6 = sizeof( struct V_13 ) + 2 ;
F_3 ( V_2 , V_15 ) ;
V_2 -> V_14 = 1 ;
}
static inline char *
F_18 ( struct V_1 * V_2 , int V_16 )
{
return & ( V_2 -> V_5 [ sizeof( struct V_17 ) + V_16 ] ) ;
}
static inline T_6 F_19 ( const void * V_18 )
{
return * ( const T_6 * ) V_18 ;
}
static T_6 F_20 ( struct V_1 * V_2 , int V_16 )
{
return * ( const T_6 * ) F_18 ( V_2 , V_16 ) ;
}
static inline T_7 F_21 ( const void * V_18 )
{
return F_22 ( V_18 ) ;
}
static T_7
F_23 ( struct V_1 * V_2 , int V_16 )
{
return F_22 ( F_18 ( V_2 , V_16 ) ) ;
}
static T_7
F_24 ( struct V_1 * V_2 , int V_16 )
{
return F_25 ( F_18 ( V_2 , V_16 ) ) ;
}
static inline T_8 F_26 ( const void * V_18 )
{
return F_27 ( V_18 ) ;
}
static T_4
F_28 ( struct V_1 * V_2 , int V_16 )
{
return F_29 ( ( T_4 * ) F_18 ( V_2 , V_16 ) ) ;
}
static inline T_5 F_30 ( struct V_1 * V_2 , int V_16 ) {
return F_31 ( F_28 ( V_2 , V_16 ) ) ;
}
int
F_32 ( struct V_1 * V_2 , int V_10 , int * V_19 )
{
int V_20 ;
F_15 ( V_2 ) ;
F_6 ( V_2 , V_10 ) ;
if ( ( V_20 = F_33 ( V_2 , 33 ) ) != 0 ) {
F_34 ( V_2 ) ;
return V_20 ;
}
* V_19 = F_35 (unsigned int, ncp_reply_be16(server, 0), size) ;
F_34 ( V_2 ) ;
return 0 ;
}
int
F_36 ( struct V_1 * V_2 ,
int V_10 , int V_21 , int * V_22 , int * V_23 ) {
int V_20 ;
if ( V_10 < V_24 ) V_10 = V_24 ;
F_15 ( V_2 ) ;
F_6 ( V_2 , V_10 ) ;
F_3 ( V_2 , V_21 ) ;
if ( ( V_20 = F_33 ( V_2 , 0x61 ) ) != 0 )
{
F_34 ( V_2 ) ;
return V_20 ;
}
V_20 = F_24 ( V_2 , 0 ) ;
if ( V_20 >= V_24 )
V_10 = F_37 ( V_20 , V_10 ) ;
* V_22 = V_10 ;
* V_23 = F_20 ( V_2 , 4 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 ,
int V_25 , struct V_26 * V_19 ) {
int V_20 ;
int V_12 ;
F_17 ( V_2 , 44 ) ;
F_3 ( V_2 , V_25 ) ;
if ( ( V_20 = F_33 ( V_2 , 22 ) ) != 0 ) {
goto V_27;
}
V_19 -> V_28 = F_30 ( V_2 , 0 ) ;
V_19 -> V_29 = F_30 ( V_2 , 4 ) ;
V_19 -> V_30 = F_30 ( V_2 , 8 ) ;
V_19 -> V_31 = F_30 ( V_2 , 12 ) ;
V_19 -> V_32 = F_30 ( V_2 , 16 ) ;
V_19 -> V_33 = F_30 ( V_2 , 20 ) ;
V_19 -> V_34 = F_20 ( V_2 , 28 ) ;
memset ( & ( V_19 -> V_35 ) , 0 , sizeof( V_19 -> V_35 ) ) ;
V_20 = - V_36 ;
V_12 = F_20 ( V_2 , 29 ) ;
if ( V_12 > V_37 ) {
F_2 ( L_3 , V_12 ) ;
goto V_27;
}
memcpy ( & ( V_19 -> V_35 ) , F_18 ( V_2 , 30 ) , V_12 ) ;
V_20 = 0 ;
V_27:
F_34 ( V_2 ) ;
return V_20 ;
}
int F_39 ( struct V_1 * V_2 , T_1 V_25 ,
struct V_26 * V_19 ) {
int V_20 ;
int V_12 ;
F_17 ( V_2 , 45 ) ;
F_3 ( V_2 , V_25 ) ;
if ( ( V_20 = F_33 ( V_2 , 22 ) ) != 0 ) {
goto V_27;
}
V_19 -> V_28 = F_30 ( V_2 , 0 ) ;
V_19 -> V_29 = F_30 ( V_2 , 4 ) ;
V_19 -> V_30 = 0 ;
V_19 -> V_31 = 0 ;
V_19 -> V_32 = F_30 ( V_2 , 8 ) ;
V_19 -> V_33 = F_30 ( V_2 , 12 ) ;
V_19 -> V_34 = F_20 ( V_2 , 20 ) ;
memset ( & ( V_19 -> V_35 ) , 0 , sizeof( V_19 -> V_35 ) ) ;
V_20 = - V_36 ;
V_12 = F_20 ( V_2 , 21 ) ;
if ( V_12 > V_37 ) {
F_2 ( L_3 , V_12 ) ;
goto V_27;
}
memcpy ( & ( V_19 -> V_35 ) , F_18 ( V_2 , 22 ) , V_12 ) ;
V_20 = 0 ;
V_27:
F_34 ( V_2 ) ;
return V_20 ;
}
int
F_40 ( struct V_1 * V_2 , const char * V_38 )
{
int V_20 ;
F_15 ( V_2 ) ;
F_3 ( V_2 , 0 ) ;
F_13 ( V_2 , V_38 , 6 ) ;
V_20 = F_33 ( V_2 , 66 ) ;
F_34 ( V_2 ) ;
return V_20 ;
}
int
F_41 ( struct V_39 * V_39 )
{
int V_40 ;
V_40 = 0 ;
F_42 ( & F_43 ( V_39 ) -> V_41 ) ;
if ( F_44 ( & F_43 ( V_39 ) -> V_42 ) == 1 ) {
F_45 ( & F_43 ( V_39 ) -> V_42 , 0 ) ;
V_40 = F_40 ( F_46 ( V_39 ) , F_43 ( V_39 ) -> V_43 ) ;
if ( ! V_40 )
F_47 ( L_4 ,
F_43 ( V_39 ) -> V_44 ,
F_43 ( V_39 ) -> V_45 , V_40 ) ;
}
F_48 ( & F_43 ( V_39 ) -> V_41 ) ;
return V_40 ;
}
static void F_49 ( struct V_1 * V_2 , T_1 V_46 ,
T_4 V_47 , int V_48 ,
const char * V_49 )
{
F_3 ( V_2 , V_46 ) ;
F_8 ( V_2 , V_47 ) ;
if ( V_48 != 0 ) {
F_3 ( V_2 , 1 ) ;
} else {
F_3 ( V_2 , 0xff ) ;
}
if ( V_49 != NULL ) {
F_3 ( V_2 , 1 ) ;
F_14 ( V_2 , V_49 ) ;
} else {
F_3 ( V_2 , 0 ) ;
}
}
int F_50 ( struct V_1 * V_2 , T_1 V_50 , T_4 V_51 ,
T_1 * V_52 ) {
int V_20 ;
F_15 ( V_2 ) ;
F_3 ( V_2 , 12 ) ;
F_3 ( V_2 , V_53 ) ;
F_3 ( V_2 , 0 ) ;
F_4 ( V_2 , 0 ) ;
F_49 ( V_2 , V_50 , V_51 , 1 , NULL ) ;
if ( ( V_20 = F_33 ( V_2 , 87 ) ) == 0 ) {
* V_52 = F_20 ( V_2 , 0 ) ;
}
F_34 ( V_2 ) ;
return V_20 ;
}
int F_51 ( struct V_1 * V_2 , T_1 V_52 ) {
int V_20 ;
F_17 ( V_2 , 20 ) ;
F_3 ( V_2 , V_52 ) ;
V_20 = F_33 ( V_2 , 22 ) ;
F_34 ( V_2 ) ;
return V_20 ;
}
void F_52 ( const void * V_54 , struct V_55 * V_19 )
{
const T_1 * V_56 ;
const int V_57 = F_53 ( struct V_55 , V_58 ) ;
memcpy ( V_19 , V_54 , V_57 ) ;
V_56 = V_54 + V_57 ;
V_19 -> V_58 = * V_56 ;
memcpy ( V_19 -> V_59 , V_56 + 1 , * V_56 ) ;
V_19 -> V_59 [ * V_56 ] = '\0' ;
V_19 -> V_44 = F_31 ( V_19 -> V_44 ) ;
return;
}
static inline void F_54 ( const unsigned char * V_54 ,
struct V_60 * V_19 )
{
V_19 -> V_61 = F_26 ( V_54 ) ;
V_19 -> V_62 = F_26 ( V_54 + 8 ) ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_55 * V_19 )
{
int V_20 = 0 ;
#ifdef F_56
T_5 V_50 = V_19 -> V_44 ;
if ( F_57 ( V_2 , V_50 ) ) {
F_15 ( V_2 ) ;
F_3 ( V_2 , 19 ) ;
F_3 ( V_2 , V_2 -> V_63 [ V_50 ] ) ;
F_3 ( V_2 , V_64 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , V_50 ) ;
F_8 ( V_2 , V_19 -> V_45 ) ;
F_11 ( V_2 , V_65 | V_66 | V_67 ) ;
if ( ( V_20 = F_33 ( V_2 , 87 ) ) == 0 ) {
F_54 ( F_18 ( V_2 , 0 ) , & V_19 -> V_68 ) ;
F_2 ( V_69
L_5 ,
V_19 -> V_59 , V_19 -> V_68 . V_61 ,
V_19 -> V_68 . V_62 ) ;
} else {
V_19 -> V_68 . V_61 = 0 ;
V_19 -> V_68 . V_62 = 0 ;
}
F_34 ( V_2 ) ;
} else
#endif
{
V_19 -> V_68 . V_61 = 0 ;
V_19 -> V_68 . V_62 = 0 ;
}
return V_20 ;
}
int F_58 ( struct V_1 * V_2 , struct V_39 * V_70 , const char * V_49 ,
struct V_55 * V_19 )
{
T_1 V_50 = F_43 ( V_70 ) -> V_44 ;
T_4 V_51 = F_43 ( V_70 ) -> V_45 ;
int V_20 ;
if ( V_19 == NULL ) {
F_59 ( V_71 L_6 ) ;
return - V_72 ;
}
F_15 ( V_2 ) ;
F_3 ( V_2 , 6 ) ;
F_3 ( V_2 , V_2 -> V_63 [ V_50 ] ) ;
F_3 ( V_2 , V_2 -> V_63 [ V_50 ] ) ;
F_4 ( V_2 , F_60 ( 0x8006 ) ) ;
F_8 ( V_2 , V_73 ) ;
F_49 ( V_2 , V_50 , V_51 , 1 , V_49 ) ;
if ( ( V_20 = F_33 ( V_2 , 87 ) ) != 0 )
goto V_27;
F_52 ( F_18 ( V_2 , 0 ) , V_19 ) ;
F_34 ( V_2 ) ;
V_20 = F_55 ( V_2 , V_19 ) ;
return V_20 ;
V_27:
F_34 ( V_2 ) ;
return V_20 ;
}
static int
F_61 ( struct V_1 * V_2 ,
T_1 V_74 , T_1 V_50 , T_4 V_51 ,
const char * V_49 ,
T_4 * V_75 )
{
int V_20 ;
F_15 ( V_2 ) ;
F_3 ( V_2 , 6 ) ;
F_3 ( V_2 , V_74 ) ;
F_3 ( V_2 , V_74 ) ;
F_4 ( V_2 , F_60 ( 0x8006 ) ) ;
F_8 ( V_2 , V_76 ) ;
F_49 ( V_2 , V_50 , V_51 , 1 , V_49 ) ;
if ( ( V_20 = F_33 ( V_2 , 87 ) ) == 0 )
{
if ( V_75 ) * V_75 = F_28 ( V_2 , 0x34 ) ;
}
F_34 ( V_2 ) ;
return V_20 ;
}
static inline int
F_62 ( struct V_1 * V_2 , T_1 V_77 )
{
#if F_63 ( V_78 ) || F_63 ( F_56 )
int V_20 ;
T_1 * V_79 ;
T_3 V_80 ;
F_15 ( V_2 ) ;
F_3 ( V_2 , 24 ) ;
F_4 ( V_2 , 0 ) ;
F_3 ( V_2 , V_77 ) ;
if ( ( V_20 = F_33 ( V_2 , 87 ) ) != 0 ) {
F_34 ( V_2 ) ;
return V_53 ;
}
V_20 = V_53 ;
V_80 = F_23 ( V_2 , 0 ) ;
V_79 = F_18 ( V_2 , 2 ) ;
while ( V_80 > 0 ) {
F_2 ( L_7 , * V_79 , V_77 ) ;
#ifdef F_56
if ( ( * V_79 == V_64 ) && ! ( V_2 -> V_81 . V_82 & V_83 ) )
{
V_20 = V_64 ;
break;
}
#endif
#ifdef V_78
if ( ( * V_79 == V_84 ) && ! ( V_2 -> V_81 . V_82 & V_85 ) )
{
V_20 = V_84 ;
}
#endif
V_79 += 1 ;
V_80 -= 1 ;
}
F_34 ( V_2 ) ;
return V_20 ;
#else
return V_53 ;
#endif
}
int
F_64 ( struct V_1 * V_2 , T_1 V_77 , int * V_86 )
{
int V_74 = F_62 ( V_2 , V_77 ) ;
if ( V_86 )
* V_86 = V_74 ;
F_2 ( L_8 ,
V_77 , V_2 -> V_63 [ V_77 ] ) ;
if ( V_2 -> V_63 [ V_77 ] == V_74 )
return 0 ;
V_2 -> V_63 [ V_77 ] = V_74 ;
return 1 ;
}
static int
F_65 ( struct V_1 * V_2 ,
T_1 V_87 , T_1 V_88 , T_1 V_46 , T_4 V_47 ,
const char * V_49 ,
T_4 * V_45 , T_4 * V_89 )
{
int V_20 ;
F_15 ( V_2 ) ;
F_3 ( V_2 , 6 ) ;
F_3 ( V_2 , V_87 ) ;
F_3 ( V_2 , V_88 ) ;
F_4 ( V_2 , F_60 ( 0x8006 ) ) ;
F_8 ( V_2 , V_73 ) ;
F_49 ( V_2 , V_46 , V_47 , 1 , V_49 ) ;
if ( ( V_20 = F_33 ( V_2 , 87 ) ) != 0 )
{
F_34 ( V_2 ) ;
return V_20 ;
}
if ( V_45 )
* V_45 = F_28 ( V_2 , 0x30 ) ;
if ( V_89 )
* V_89 = F_28 ( V_2 , 0x34 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
int
F_66 ( struct V_1 * V_2 ,
T_1 V_44 , T_1 V_90 , T_4 V_45 ,
T_5 * V_77 , T_4 * V_91 , T_4 * V_92 )
{
int V_93 ;
int V_20 ;
F_64 ( V_2 , V_44 , & V_93 ) ;
if ( ( V_20 = F_65 ( V_2 , V_90 , V_93 , V_44 ,
V_45 , NULL , V_91 , V_92 ) ) != 0 )
{
return V_20 ;
}
* V_77 = V_44 ;
V_2 -> V_81 . V_94 [ 1 ] = 0 ;
V_2 -> V_81 . V_94 [ 0 ] = 'X' ;
return 0 ;
}
int
F_67 ( struct V_1 * V_2 ,
const char * V_95 , T_5 * V_77 , T_4 * V_51 , T_4 * V_96 )
{
int V_20 ;
F_2 ( L_9 , V_95 ) ;
F_15 ( V_2 ) ;
F_3 ( V_2 , 22 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_3 ( V_2 , 0xff ) ;
F_3 ( V_2 , 1 ) ;
F_14 ( V_2 , V_95 ) ;
if ( ( V_20 = F_33 ( V_2 , 87 ) ) != 0 ) {
F_34 ( V_2 ) ;
return V_20 ;
}
* V_51 = * V_96 = F_28 ( V_2 , 4 ) ;
* V_77 = F_20 ( V_2 , 8 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
int
F_68 ( struct V_1 * V_2 ,
const char * V_95 , struct V_55 * V_19 )
{
int V_20 ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_20 = F_67 ( V_2 , V_95 ,
& V_19 -> V_44 , & V_19 -> V_45 , & V_19 -> V_89 ) ;
if ( V_20 ) {
return V_20 ;
}
F_64 ( V_2 , V_19 -> V_44 , NULL ) ;
V_19 -> V_58 = strlen ( V_95 ) ;
memcpy ( V_19 -> V_59 , V_95 , V_19 -> V_58 + 1 ) ;
V_19 -> V_97 = V_98 ;
V_19 -> V_99 = V_19 -> V_100 = F_60 ( 0x0000 ) ;
V_19 -> V_101 = V_19 -> V_102 = V_19 -> V_103 = F_60 ( 0x0C21 ) ;
V_19 -> V_68 . V_61 = 0 ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_39 * V_70 ,
const char * V_49 ,
T_4 V_104 ,
const struct V_105 * V_106 )
{
T_1 V_50 = F_43 ( V_70 ) -> V_44 ;
T_4 V_51 = F_43 ( V_70 ) -> V_45 ;
int V_20 ;
F_15 ( V_2 ) ;
F_3 ( V_2 , 7 ) ;
F_3 ( V_2 , V_2 -> V_63 [ V_50 ] ) ;
F_3 ( V_2 , 0 ) ;
F_4 ( V_2 , F_60 ( 0x8006 ) ) ;
F_8 ( V_2 , V_104 ) ;
F_13 ( V_2 , V_106 , sizeof( * V_106 ) ) ;
F_49 ( V_2 , V_50 , V_51 , 1 , V_49 ) ;
V_20 = F_33 ( V_2 , 87 ) ;
F_34 ( V_2 ) ;
return V_20 ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_39 * V_70 ,
T_4 V_104 ,
const struct V_105 * V_106 )
{
return F_69 ( V_2 , V_70 , NULL ,
V_104 , V_106 ) ;
}
int F_71 ( struct V_1 * V_2 , T_1 V_50 , T_4 V_51 ,
T_5 V_61 , T_5 V_62 )
{
int V_20 = 0 ;
F_15 ( V_2 ) ;
if ( V_2 -> V_63 [ V_50 ] == V_64 ) {
F_3 ( V_2 , 25 ) ;
F_3 ( V_2 , V_2 -> V_63 [ V_50 ] ) ;
F_3 ( V_2 , V_64 ) ;
F_3 ( V_2 , V_50 ) ;
F_8 ( V_2 , V_51 ) ;
F_11 ( V_2 , V_65 | V_66 | V_67 ) ;
F_11 ( V_2 , V_61 ) ;
F_11 ( V_2 , 1 ) ;
F_11 ( V_2 , V_62 ) ;
V_20 = F_33 ( V_2 , 87 ) ;
}
F_34 ( V_2 ) ;
return V_20 ;
}
static int
F_72 ( struct V_1 * V_2 ,
T_1 V_48 , T_1 V_50 , T_4 V_51 ,
const char * V_107 , T_1 V_74 , T_2 V_108 )
{
int V_20 ;
F_15 ( V_2 ) ;
F_3 ( V_2 , 8 ) ;
F_3 ( V_2 , V_74 ) ;
F_3 ( V_2 , 0 ) ;
F_4 ( V_2 , V_108 ) ;
F_49 ( V_2 , V_50 , V_51 , V_48 , V_107 ) ;
V_20 = F_33 ( V_2 , 87 ) ;
F_34 ( V_2 ) ;
return V_20 ;
}
int
F_73 ( struct V_1 * V_2 ,
struct V_109 * V_109 )
{
struct V_39 * V_39 = V_109 -> V_110 ;
T_1 V_50 ;
T_4 V_51 ;
if ( ! V_39 ) {
return 0xFF ;
}
V_50 = F_43 ( V_39 ) -> V_44 ;
V_51 = F_43 ( V_39 ) -> V_89 ;
return F_72 ( V_2 , 1 , V_50 , V_51 , NULL , V_53 , F_60 ( 0x8006 ) ) ;
}
int
F_74 ( struct V_1 * V_2 ,
struct V_39 * V_70 , const char * V_107 )
{
T_1 V_50 = F_43 ( V_70 ) -> V_44 ;
T_4 V_51 = F_43 ( V_70 ) -> V_45 ;
int V_63 ;
V_63 = V_2 -> V_63 [ V_50 ] ;
#ifdef F_56
if ( V_63 == V_64 )
{
int V_20 ;
V_20 = F_61 ( V_2 , V_63 , V_50 , V_51 , V_107 , & V_51 ) ;
if ( V_20 ) return V_20 ;
V_107 = NULL ;
V_63 = V_53 ;
}
#endif
return F_72 ( V_2 , 1 , V_50 , V_51 , V_107 , V_63 , F_60 ( 0x8006 ) ) ;
}
static inline void F_75 ( T_3 V_111 , T_3 V_112 , T_1 V_113 [ 6 ] )
{
T_2 * V_114 = ( T_2 * ) V_113 ;
V_114 [ 1 ] = F_60 ( V_111 ) ;
V_114 [ 2 ] = F_60 ( V_112 ) ;
V_114 [ 0 ] = F_60 ( V_111 + 1 ) ;
return;
}
int F_76 ( struct V_1 * V_2 ,
struct V_39 * V_70 , const char * V_107 ,
int V_115 ,
T_4 V_116 ,
T_2 V_117 ,
struct V_118 * V_19 )
{
T_2 V_119 = F_60 ( 0x0006 ) ;
T_1 V_50 ;
T_4 V_51 ;
int V_20 ;
V_50 = F_43 ( V_70 ) -> V_44 ;
V_51 = F_43 ( V_70 ) -> V_45 ;
if ( ( V_116 & V_98 ) != 0 ) {
V_119 |= F_60 ( 0x8000 ) ;
}
F_15 ( V_2 ) ;
F_3 ( V_2 , 1 ) ;
F_3 ( V_2 , V_2 -> V_63 [ V_50 ] ) ;
F_3 ( V_2 , V_115 ) ;
F_4 ( V_2 , V_119 ) ;
F_8 ( V_2 , V_73 ) ;
F_8 ( V_2 , V_116 ) ;
F_4 ( V_2 , V_117 ) ;
F_49 ( V_2 , V_50 , V_51 , 1 , V_107 ) ;
if ( ( V_20 = F_33 ( V_2 , 87 ) ) != 0 )
goto V_27;
if ( ! ( V_116 & V_98 ) )
V_19 -> V_42 = 1 ;
F_52 ( F_18 ( V_2 , 6 ) , & ( V_19 -> V_120 ) ) ;
V_19 -> V_77 = V_19 -> V_120 . V_44 ;
F_75 ( F_23 ( V_2 , 0 ) ,
F_23 ( V_2 , 2 ) ,
V_19 -> V_43 ) ;
F_34 ( V_2 ) ;
( void ) F_55 ( V_2 , & ( V_19 -> V_120 ) ) ;
return 0 ;
V_27:
F_34 ( V_2 ) ;
return V_20 ;
}
int
F_77 ( struct V_1 * V_2 , struct V_39 * V_70 ,
struct V_121 * V_19 )
{
T_1 V_50 = F_43 ( V_70 ) -> V_44 ;
T_4 V_51 = F_43 ( V_70 ) -> V_45 ;
int V_20 ;
F_15 ( V_2 ) ;
F_3 ( V_2 , 2 ) ;
F_3 ( V_2 , V_2 -> V_63 [ V_50 ] ) ;
F_3 ( V_2 , 0 ) ;
F_49 ( V_2 , V_50 , V_51 , 1 , NULL ) ;
V_20 = F_33 ( V_2 , 87 ) ;
if ( V_20 )
goto V_27;
memcpy ( V_19 , F_18 ( V_2 , 0 ) , sizeof( * V_19 ) ) ;
V_27:
F_34 ( V_2 ) ;
return V_20 ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_121 * V_122 ,
int * V_123 ,
int * V_124 ,
char * V_125 ,
T_9 V_126 ,
char * * V_127 ,
T_9 * V_128 )
{
int V_20 ;
F_15 ( V_2 ) ;
F_3 ( V_2 , 20 ) ;
F_3 ( V_2 , V_2 -> V_63 [ V_122 -> V_44 ] ) ;
F_3 ( V_2 , 0 ) ;
F_4 ( V_2 , F_60 ( 0x8006 ) ) ;
F_8 ( V_2 , V_73 ) ;
F_4 ( V_2 , F_60 ( 32767 ) ) ;
F_13 ( V_2 , V_122 , 9 ) ;
#ifdef F_56
if ( V_2 -> V_63 [ V_122 -> V_44 ] == V_64 ) {
F_3 ( V_2 , 0 ) ;
} else
#endif
{
F_3 ( V_2 , 2 ) ;
F_3 ( V_2 , 0xff ) ;
F_3 ( V_2 , '*' ) ;
}
V_20 = F_79 ( V_2 , 87 , V_125 , V_126 ) ;
if ( V_20 ) {
F_34 ( V_2 ) ;
return V_20 ;
}
if ( V_2 -> V_129 < 12 ) {
F_34 ( V_2 ) ;
return 0xFF ;
}
* V_128 = V_2 -> V_129 - 12 ;
F_34 ( V_2 ) ;
V_125 = V_125 + sizeof( struct V_17 ) ;
* V_127 = V_125 + 12 ;
* V_124 = F_21 ( V_125 + 10 ) ;
* V_123 = F_19 ( V_125 + 9 ) ;
memcpy ( V_122 , V_125 , 9 ) ;
return 0 ;
}
static int
F_80 ( struct V_1 * V_2 ,
struct V_39 * V_130 , const char * V_131 , T_2 V_132 ,
struct V_39 * V_133 , const char * V_134 )
{
int V_20 = - V_72 ;
if ( ( V_130 == NULL ) || ( V_131 == NULL ) ||
( V_133 == NULL ) || ( V_134 == NULL ) )
goto V_27;
F_15 ( V_2 ) ;
F_3 ( V_2 , 4 ) ;
F_3 ( V_2 , V_2 -> V_63 [ F_43 ( V_130 ) -> V_44 ] ) ;
F_3 ( V_2 , 1 ) ;
F_4 ( V_2 , V_132 ) ;
F_3 ( V_2 , F_43 ( V_130 ) -> V_44 ) ;
F_8 ( V_2 , F_43 ( V_130 ) -> V_45 ) ;
F_3 ( V_2 , 1 ) ;
F_3 ( V_2 , 1 ) ;
F_3 ( V_2 , F_43 ( V_133 ) -> V_44 ) ;
F_8 ( V_2 , F_43 ( V_133 ) -> V_45 ) ;
F_3 ( V_2 , 1 ) ;
F_3 ( V_2 , 1 ) ;
F_14 ( V_2 , V_131 ) ;
F_14 ( V_2 , V_134 ) ;
V_20 = F_33 ( V_2 , 87 ) ;
F_34 ( V_2 ) ;
V_27:
return V_20 ;
}
int F_81 ( struct V_1 * V_2 ,
struct V_39 * V_130 , const char * V_131 ,
struct V_39 * V_133 , const char * V_134 )
{
int V_20 ;
T_2 V_132 = F_60 ( 0x06 ) ;
V_20 = F_80 ( V_2 , V_130 , V_131 , V_132 ,
V_133 , V_134 ) ;
if ( V_20 == 0xFF )
{
V_132 = F_60 ( 0x16 ) ;
V_20 = F_80 ( V_2 , V_130 , V_131 , V_132 ,
V_133 , V_134 ) ;
}
if ( V_20 != 0x92 ) return V_20 ;
V_20 = F_74 ( V_2 , V_133 , V_134 ) ;
if ( V_20 != 0 ) return - V_135 ;
V_20 = F_80 ( V_2 , V_130 , V_131 , V_132 ,
V_133 , V_134 ) ;
return V_20 ;
}
int
F_82 ( struct V_1 * V_2 , const char * V_38 ,
T_5 V_16 , T_3 V_136 , char * V_19 , int * V_137 )
{
const char * V_9 ;
int V_20 ;
F_15 ( V_2 ) ;
F_3 ( V_2 , 0 ) ;
F_13 ( V_2 , V_38 , 6 ) ;
F_9 ( V_2 , V_16 ) ;
F_6 ( V_2 , V_136 ) ;
if ( ( V_20 = F_33 ( V_2 , 72 ) ) != 0 ) {
goto V_27;
}
* V_137 = F_24 ( V_2 , 0 ) ;
V_9 = F_18 ( V_2 , 2 + ( V_16 & 1 ) ) ;
memcpy ( V_19 , V_9 , * V_137 ) ;
V_27:
F_34 ( V_2 ) ;
return V_20 ;
}
int
F_83 ( struct V_1 * V_2 , const char * V_38 ,
T_5 V_16 , T_3 V_136 , char T_10 * V_19 , int * V_137 ,
void * V_138 , T_5 V_126 )
{
int V_20 ;
F_15 ( V_2 ) ;
F_3 ( V_2 , 0 ) ;
F_13 ( V_2 , V_38 , 6 ) ;
F_9 ( V_2 , V_16 ) ;
F_6 ( V_2 , V_136 ) ;
V_20 = F_79 ( V_2 , 72 , V_138 , V_126 ) ;
F_34 ( V_2 ) ;
if ( ! V_20 ) {
int V_12 = F_25 ( ( char * ) V_138 +
sizeof( struct V_17 ) ) ;
V_20 = - V_36 ;
if ( V_12 <= V_136 ) {
char * V_9 ;
V_9 = ( char * ) V_138 +
sizeof( struct V_17 ) + 2 +
( V_16 & 1 ) ;
* V_137 = V_12 ;
V_20 = 0 ;
if ( F_84 ( V_19 , V_9 , V_12 ) )
V_20 = - V_139 ;
}
}
return V_20 ;
}
int
F_85 ( struct V_1 * V_2 , const char * V_38 ,
T_5 V_16 , T_3 V_140 ,
const char * V_9 , int * V_141 )
{
int V_20 ;
F_15 ( V_2 ) ;
F_3 ( V_2 , 0 ) ;
F_13 ( V_2 , V_38 , 6 ) ;
F_9 ( V_2 , V_16 ) ;
F_6 ( V_2 , V_140 ) ;
F_13 ( V_2 , V_9 , V_140 ) ;
if ( ( V_20 = F_33 ( V_2 , 73 ) ) == 0 )
* V_141 = V_140 ;
F_34 ( V_2 ) ;
return V_20 ;
}
int
F_86 ( struct V_1 * V_2 , const char * V_38 ,
T_1 V_142 , T_5 V_16 , T_5 V_143 , T_3 V_144 )
{
int V_20 ;
F_15 ( V_2 ) ;
F_3 ( V_2 , V_142 ) ;
F_13 ( V_2 , V_38 , 6 ) ;
F_9 ( V_2 , V_16 ) ;
F_9 ( V_2 , V_143 ) ;
F_6 ( V_2 , V_144 ) ;
if ( ( V_20 = F_33 ( V_2 , 0x1A ) ) != 0 )
{
F_34 ( V_2 ) ;
return V_20 ;
}
F_34 ( V_2 ) ;
return 0 ;
}
int
F_87 ( struct V_1 * V_2 , const char * V_38 ,
T_5 V_16 , T_5 V_143 )
{
int V_20 ;
F_15 ( V_2 ) ;
F_3 ( V_2 , 0 ) ;
F_13 ( V_2 , V_38 , 6 ) ;
F_9 ( V_2 , V_16 ) ;
F_9 ( V_2 , V_143 ) ;
if ( ( V_20 = F_33 ( V_2 , 0x1E ) ) != 0 )
{
F_34 ( V_2 ) ;
return V_20 ;
}
F_34 ( V_2 ) ;
return 0 ;
}
int
F_88 ( struct V_1 * V_2 , unsigned char * V_145 , unsigned int * V_146 ,
const unsigned char * V_147 , unsigned int V_148 , int V_149 )
{
struct V_150 * V_151 = V_2 -> V_152 ;
struct V_150 * V_27 = V_2 -> V_153 ;
unsigned char * V_154 ;
unsigned char * V_155 ;
const unsigned char * V_156 ;
V_156 = V_147 + V_148 ;
V_154 = V_145 ;
V_155 = V_145 + * V_146 - 1 ;
while ( V_147 < V_156 ) {
int V_157 ;
T_11 V_158 ;
if ( F_89 ( V_2 , V_159 ) ) {
int V_160 ;
T_12 V_161 ;
V_160 = F_90 ( V_147 , V_156 - V_147 , & V_161 ) ;
if ( V_160 < 0 || V_161 > V_162 )
return - V_72 ;
V_147 += V_160 ;
V_158 = V_161 ;
} else {
if ( * V_147 == V_163 ) {
int V_160 ;
if ( V_156 - V_147 < 5 )
goto V_164;
V_158 = 0 ;
for ( V_160 = 1 ; V_160 < 5 ; V_160 ++ ) {
unsigned char V_165 ;
V_165 = V_147 [ V_160 ] - '0' ;
if ( V_165 >= 10 ) {
V_165 -= 'A' - '0' - 10 ;
if ( ( V_165 < 10 ) || ( V_165 > 15 ) ) {
goto V_164;
}
}
V_158 = ( V_158 << 4 ) | V_165 ;
}
V_147 += 5 ;
} else {
V_164: ;
if ( ( V_157 = V_151 -> V_166 ( V_147 , V_156 - V_147 , & V_158 ) ) < 0 )
return V_157 ;
V_147 += V_157 ;
}
}
V_157 = V_27 -> V_167 ( V_158 , V_145 , V_155 - V_145 ) ;
if ( V_157 < 0 )
return V_157 ;
if ( V_149 ) {
int V_168 ;
for ( V_168 = 0 ; V_168 < V_157 ; V_168 ++ ) {
V_145 [ V_168 ] = F_91 ( V_27 , V_145 [ V_168 ] ) ;
}
}
V_145 += V_157 ;
}
* V_145 = 0 ;
* V_146 = V_145 - V_154 ;
return 0 ;
}
int
F_92 ( struct V_1 * V_2 , unsigned char * V_147 , unsigned int * V_148 ,
const unsigned char * V_145 , unsigned int V_146 , int V_149 )
{
struct V_150 * V_151 = V_2 -> V_153 ;
struct V_150 * V_27 = V_2 -> V_152 ;
const unsigned char * V_155 ;
unsigned char * V_169 ;
unsigned char * V_156 ;
unsigned char * V_170 ;
int V_40 ;
V_170 = NULL ;
if ( V_149 ) {
int V_120 ;
V_170 = F_93 ( V_146 , V_171 ) ;
if ( ! V_170 )
return - V_172 ;
for ( V_120 = 0 ; V_120 < V_146 ; V_120 ++ )
V_170 [ V_120 ] = F_94 ( V_151 , V_145 [ V_120 ] ) ;
V_145 = V_170 ;
}
V_169 = V_147 ;
V_156 = V_147 + * V_148 - 1 ;
V_155 = V_145 + V_146 ;
while ( V_145 < V_155 ) {
T_11 V_158 ;
int V_157 ;
if ( ( V_157 = V_151 -> V_166 ( V_145 , V_155 - V_145 , & V_158 ) ) < 0 ) {
V_40 = V_157 ;
goto V_173;
}
V_145 += V_157 ;
if ( F_89 ( V_2 , V_159 ) ) {
int V_160 ;
V_160 = F_95 ( V_158 , V_147 , V_156 - V_147 ) ;
if ( V_160 < 0 ) {
V_40 = - V_174 ;
goto V_173;
}
V_147 += V_160 ;
} else {
if ( ( V_157 = V_27 -> V_167 ( V_158 , V_147 , V_156 - V_147 ) ) >= 0 ) {
V_147 += V_157 ;
} else {
int V_160 ;
if ( V_156 - V_147 < 5 ) {
V_40 = - V_174 ;
goto V_173;
}
* V_147 = V_163 ;
for ( V_160 = 4 ; V_160 > 0 ; V_160 -- ) {
unsigned char V_175 ;
V_175 = ( V_158 & 0xF ) + '0' ;
if ( V_175 > '9' ) {
V_175 += 'A' - '9' - 1 ;
}
V_147 [ V_160 ] = V_175 ;
V_158 >>= 4 ;
}
V_147 += 5 ;
}
}
}
* V_147 = 0 ;
* V_148 = V_147 - V_169 ;
V_40 = 0 ;
V_173: ;
if ( V_149 )
F_96 ( V_170 ) ;
return V_40 ;
}
int
F_88 ( unsigned char * V_145 , unsigned int * V_146 ,
const unsigned char * V_147 , unsigned int V_148 , int V_149 )
{
int V_120 ;
if ( * V_146 <= V_148 )
return - V_174 ;
if ( V_149 )
for ( V_120 = 0 ; V_120 < V_148 ; V_120 ++ ) {
* V_145 = toupper ( * V_147 ) ;
V_145 ++ ;
V_147 ++ ;
}
else {
memmove ( V_145 , V_147 , V_148 ) ;
V_145 += V_148 ;
}
* V_146 = V_148 ;
* V_145 = 0 ;
return 0 ;
}
int
F_92 ( unsigned char * V_147 , unsigned int * V_148 ,
const unsigned char * V_145 , unsigned int V_146 , int V_149 )
{
int V_120 ;
if ( * V_148 <= V_146 )
return - V_174 ;
if ( V_149 )
for ( V_120 = 0 ; V_120 < V_146 ; V_120 ++ ) {
* V_147 = tolower ( * V_145 ) ;
V_147 ++ ;
V_145 ++ ;
}
else {
memmove ( V_147 , V_145 , V_146 ) ;
V_147 += V_146 ;
}
* V_148 = V_146 ;
* V_147 = 0 ;
return 0 ;
}
