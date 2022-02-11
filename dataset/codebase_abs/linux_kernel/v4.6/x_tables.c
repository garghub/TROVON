int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_3 ( & V_2 -> V_7 , & V_5 [ V_3 ] . V_2 ) ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
return 0 ;
}
void
F_5 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_6 ( & V_2 -> V_7 ) ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
}
int
F_7 ( struct V_1 * V_2 , unsigned int V_8 )
{
unsigned int V_9 ;
int V_10 = 0 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
V_10 = F_1 ( & V_2 [ V_9 ] ) ;
if ( V_10 )
goto V_10;
}
return V_10 ;
V_10:
if ( V_9 > 0 )
F_8 ( V_2 , V_9 ) ;
return V_10 ;
}
void
F_8 ( struct V_1 * V_2 , unsigned int V_8 )
{
while ( V_8 -- > 0 )
F_5 ( & V_2 [ V_8 ] ) ;
}
int F_9 ( struct V_11 * V_12 )
{
T_1 V_3 = V_12 -> V_4 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_3 ( & V_12 -> V_7 , & V_5 [ V_3 ] . V_12 ) ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
return 0 ;
}
void
F_10 ( struct V_11 * V_12 )
{
T_1 V_3 = V_12 -> V_4 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_6 ( & V_12 -> V_7 ) ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
}
int
F_11 ( struct V_11 * V_12 , unsigned int V_8 )
{
unsigned int V_9 ;
int V_10 = 0 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
V_10 = F_9 ( & V_12 [ V_9 ] ) ;
if ( V_10 )
goto V_10;
}
return V_10 ;
V_10:
if ( V_9 > 0 )
F_12 ( V_12 , V_9 ) ;
return V_10 ;
}
void
F_12 ( struct V_11 * V_12 , unsigned int V_8 )
{
while ( V_8 -- > 0 )
F_10 ( & V_12 [ V_8 ] ) ;
}
struct V_11 * F_13 ( T_2 V_3 , const char * V_13 , T_2 V_14 )
{
struct V_11 * V_15 ;
int V_10 = - V_16 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_14 (m, &xt[af].match, list) {
if ( strcmp ( V_15 -> V_13 , V_13 ) == 0 ) {
if ( V_15 -> V_14 == V_14 ) {
if ( F_15 ( V_15 -> V_17 ) ) {
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
return V_15 ;
}
} else
V_10 = - V_18 ;
}
}
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
if ( V_3 != V_19 )
return F_13 ( V_19 , V_13 , V_14 ) ;
return F_16 ( V_10 ) ;
}
struct V_11 *
F_17 ( T_3 V_20 , const char * V_13 , T_3 V_14 )
{
struct V_11 * V_12 ;
V_12 = F_13 ( V_20 , V_13 , V_14 ) ;
if ( F_18 ( V_12 ) ) {
F_19 ( L_1 , V_21 [ V_20 ] , V_13 ) ;
V_12 = F_13 ( V_20 , V_13 , V_14 ) ;
}
return V_12 ;
}
struct V_1 * F_20 ( T_2 V_3 , const char * V_13 , T_2 V_14 )
{
struct V_1 * V_22 ;
int V_10 = - V_16 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_14 (t, &xt[af].target, list) {
if ( strcmp ( V_22 -> V_13 , V_13 ) == 0 ) {
if ( V_22 -> V_14 == V_14 ) {
if ( F_15 ( V_22 -> V_17 ) ) {
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
return V_22 ;
}
} else
V_10 = - V_18 ;
}
}
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
if ( V_3 != V_19 )
return F_20 ( V_19 , V_13 , V_14 ) ;
return F_16 ( V_10 ) ;
}
struct V_1 * F_21 ( T_2 V_3 , const char * V_13 , T_2 V_14 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( V_3 , V_13 , V_14 ) ;
if ( F_18 ( V_2 ) ) {
F_19 ( L_1 , V_21 [ V_3 ] , V_13 ) ;
V_2 = F_20 ( V_3 , V_13 , V_14 ) ;
}
return V_2 ;
}
static int F_22 ( T_2 V_3 , const char * V_13 , T_2 V_14 , int * V_23 )
{
const struct V_11 * V_15 ;
int V_24 = 0 ;
F_14 (m, &xt[af].match, list) {
if ( strcmp ( V_15 -> V_13 , V_13 ) == 0 ) {
if ( V_15 -> V_14 > * V_23 )
* V_23 = V_15 -> V_14 ;
if ( V_15 -> V_14 == V_14 )
V_24 = 1 ;
}
}
if ( V_3 != V_19 && ! V_24 )
return F_22 ( V_19 , V_13 , V_14 , V_23 ) ;
return V_24 ;
}
static int F_23 ( T_2 V_3 , const char * V_13 , T_2 V_14 , int * V_23 )
{
const struct V_1 * V_22 ;
int V_24 = 0 ;
F_14 (t, &xt[af].target, list) {
if ( strcmp ( V_22 -> V_13 , V_13 ) == 0 ) {
if ( V_22 -> V_14 > * V_23 )
* V_23 = V_22 -> V_14 ;
if ( V_22 -> V_14 == V_14 )
V_24 = 1 ;
}
}
if ( V_3 != V_19 && ! V_24 )
return F_23 ( V_19 , V_13 , V_14 , V_23 ) ;
return V_24 ;
}
int F_24 ( T_2 V_3 , const char * V_13 , T_2 V_14 , int V_2 ,
int * V_10 )
{
int V_24 , V_25 = - 1 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
if ( V_2 == 1 )
V_24 = F_23 ( V_3 , V_13 , V_14 , & V_25 ) ;
else
V_24 = F_22 ( V_3 , V_13 , V_14 , & V_25 ) ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
if ( V_25 == - 1 ) {
* V_10 = - V_16 ;
return 0 ;
}
* V_10 = V_25 ;
if ( ! V_24 )
* V_10 = - V_26 ;
return 1 ;
}
static char *
F_25 ( char * V_27 , T_4 V_28 , unsigned int V_29 , T_3 V_20 )
{
static const char * const V_30 [] = {
L_2 , L_3 , L_4 ,
L_5 , L_6 , L_7 ,
} ;
static const char * const V_31 [] = {
L_3 , L_4 , L_5 ,
} ;
const char * const * V_32 ;
unsigned int V_9 , V_33 ;
char * V_34 = V_27 ;
bool V_35 = false ;
int V_36 ;
V_32 = ( V_20 == V_37 ) ? V_31 : V_30 ;
V_33 = ( V_20 == V_37 ) ? F_26 ( V_31 ) :
F_26 ( V_30 ) ;
* V_34 = '\0' ;
for ( V_9 = 0 ; V_9 < V_33 ; ++ V_9 ) {
if ( ! ( V_29 & ( 1 << V_9 ) ) )
continue;
V_36 = snprintf ( V_34 , V_28 , L_8 , V_35 ? L_9 : L_10 , V_32 [ V_9 ] ) ;
if ( V_36 > 0 ) {
V_28 -= V_36 ;
V_34 += V_36 ;
}
V_35 = true ;
}
return V_27 ;
}
int F_27 ( struct V_38 * V_39 ,
unsigned int V_28 , T_1 V_40 , bool V_41 )
{
int V_42 ;
if ( F_28 ( V_39 -> V_12 -> V_43 ) != V_28 &&
V_39 -> V_12 -> V_43 != - 1 ) {
F_29 ( L_11
L_12 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_12 -> V_13 ,
V_39 -> V_12 -> V_14 ,
F_28 ( V_39 -> V_12 -> V_43 ) , V_28 ) ;
return - V_44 ;
}
if ( V_39 -> V_12 -> V_45 != NULL &&
strcmp ( V_39 -> V_12 -> V_45 , V_39 -> V_45 ) != 0 ) {
F_29 ( L_13 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_12 -> V_13 ,
V_39 -> V_12 -> V_45 , V_39 -> V_45 ) ;
return - V_44 ;
}
if ( V_39 -> V_12 -> V_46 && ( V_39 -> V_47 & ~ V_39 -> V_12 -> V_46 ) != 0 ) {
char V_48 [ 64 ] , V_49 [ 64 ] ;
F_29 ( L_14
L_15 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_12 -> V_13 ,
F_25 ( V_48 , sizeof( V_48 ) , V_39 -> V_47 ,
V_39 -> V_4 ) ,
F_25 ( V_49 , sizeof( V_49 ) , V_39 -> V_12 -> V_46 ,
V_39 -> V_4 ) ) ;
return - V_44 ;
}
if ( V_39 -> V_12 -> V_40 && ( V_39 -> V_12 -> V_40 != V_40 || V_41 ) ) {
F_29 ( L_16 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_12 -> V_13 ,
V_39 -> V_12 -> V_40 ) ;
return - V_44 ;
}
if ( V_39 -> V_12 -> V_50 != NULL ) {
V_42 = V_39 -> V_12 -> V_50 ( V_39 ) ;
if ( V_42 < 0 )
return V_42 ;
else if ( V_42 > 0 )
return - V_51 ;
}
return 0 ;
}
int F_30 ( T_1 V_3 , unsigned int V_52 , int V_53 )
{
struct V_54 * V_55 = & V_5 [ V_3 ] ;
if ( ! V_55 -> V_56 ) {
if ( ! V_55 -> V_57 )
return - V_44 ;
V_55 -> V_56 = F_31 ( sizeof( struct V_58 ) * V_55 -> V_57 ) ;
if ( ! V_55 -> V_56 )
return - V_59 ;
V_55 -> V_60 = 0 ;
}
if ( V_55 -> V_60 >= V_55 -> V_57 )
return - V_44 ;
if ( V_55 -> V_60 )
V_53 += V_55 -> V_56 [ V_55 -> V_60 - 1 ] . V_53 ;
V_55 -> V_56 [ V_55 -> V_60 ] . V_52 = V_52 ;
V_55 -> V_56 [ V_55 -> V_60 ] . V_53 = V_53 ;
V_55 -> V_60 ++ ;
return 0 ;
}
void F_32 ( T_1 V_3 )
{
if ( V_5 [ V_3 ] . V_56 ) {
F_33 ( V_5 [ V_3 ] . V_56 ) ;
V_5 [ V_3 ] . V_56 = NULL ;
V_5 [ V_3 ] . V_57 = 0 ;
V_5 [ V_3 ] . V_60 = 0 ;
}
}
int F_34 ( T_1 V_3 , unsigned int V_52 )
{
struct V_58 * V_61 = V_5 [ V_3 ] . V_56 ;
int V_62 , V_63 = 0 , V_64 = V_5 [ V_3 ] . V_60 - 1 ;
while ( V_63 <= V_64 ) {
V_62 = ( V_63 + V_64 ) >> 1 ;
if ( V_52 > V_61 [ V_62 ] . V_52 )
V_63 = V_62 + 1 ;
else if ( V_52 < V_61 [ V_62 ] . V_52 )
V_64 = V_62 - 1 ;
else
return V_62 ? V_61 [ V_62 - 1 ] . V_53 : 0 ;
}
return V_63 ? V_61 [ V_63 - 1 ] . V_53 : 0 ;
}
void F_35 ( T_1 V_3 , unsigned int V_57 )
{
V_5 [ V_3 ] . V_57 = V_57 ;
V_5 [ V_3 ] . V_60 = 0 ;
}
int F_36 ( const struct V_11 * V_12 )
{
T_5 V_65 = V_12 -> V_66 ? : V_12 -> V_43 ;
return F_28 ( V_12 -> V_43 ) - F_37 ( V_65 ) ;
}
int F_38 ( struct V_67 * V_15 , void * * V_68 ,
unsigned int * V_28 )
{
const struct V_11 * V_12 = V_15 -> V_69 . V_70 . V_12 ;
struct V_71 * V_72 = (struct V_71 * ) V_15 ;
int V_73 , V_74 = F_36 ( V_12 ) ;
T_5 V_75 = V_72 -> V_69 . V_76 . V_77 ;
V_15 = * V_68 ;
memcpy ( V_15 , V_72 , sizeof( * V_72 ) ) ;
if ( V_12 -> V_78 )
V_12 -> V_78 ( V_15 -> V_79 , V_72 -> V_79 ) ;
else
memcpy ( V_15 -> V_79 , V_72 -> V_79 , V_75 - sizeof( * V_72 ) ) ;
V_73 = F_28 ( V_12 -> V_43 ) - V_12 -> V_43 ;
if ( V_73 > 0 )
memset ( V_15 -> V_79 + V_12 -> V_43 , 0 , V_73 ) ;
V_75 += V_74 ;
V_15 -> V_69 . V_76 . V_77 = V_75 ;
* V_28 += V_74 ;
* V_68 += V_75 ;
return 0 ;
}
int F_39 ( const struct V_67 * V_15 ,
void T_6 * * V_68 , unsigned int * V_28 )
{
const struct V_11 * V_12 = V_15 -> V_69 . V_70 . V_12 ;
struct V_71 T_6 * V_72 = * V_68 ;
int V_74 = F_36 ( V_12 ) ;
T_5 V_75 = V_15 -> V_69 . V_76 . V_77 - V_74 ;
if ( F_40 ( V_72 , V_15 , sizeof( * V_72 ) ) ||
F_41 ( V_75 , & V_72 -> V_69 . V_76 . V_77 ) ||
F_40 ( V_72 -> V_69 . V_76 . V_13 , V_15 -> V_69 . V_70 . V_12 -> V_13 ,
strlen ( V_15 -> V_69 . V_70 . V_12 -> V_13 ) + 1 ) )
return - V_80 ;
if ( V_12 -> V_81 ) {
if ( V_12 -> V_81 ( ( void T_6 * ) V_72 -> V_79 , V_15 -> V_79 ) )
return - V_80 ;
} else {
if ( F_40 ( V_72 -> V_79 , V_15 -> V_79 , V_75 - sizeof( * V_72 ) ) )
return - V_80 ;
}
* V_28 -= V_74 ;
* V_68 += V_75 ;
return 0 ;
}
int F_42 ( struct V_82 * V_39 ,
unsigned int V_28 , T_1 V_40 , bool V_41 )
{
int V_42 ;
if ( F_28 ( V_39 -> V_2 -> V_83 ) != V_28 ) {
F_29 ( L_17
L_12 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_2 -> V_13 ,
V_39 -> V_2 -> V_14 ,
F_28 ( V_39 -> V_2 -> V_83 ) , V_28 ) ;
return - V_44 ;
}
if ( V_39 -> V_2 -> V_45 != NULL &&
strcmp ( V_39 -> V_2 -> V_45 , V_39 -> V_45 ) != 0 ) {
F_29 ( L_18 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_2 -> V_13 ,
V_39 -> V_2 -> V_45 , V_39 -> V_45 ) ;
return - V_44 ;
}
if ( V_39 -> V_2 -> V_46 && ( V_39 -> V_47 & ~ V_39 -> V_2 -> V_46 ) != 0 ) {
char V_48 [ 64 ] , V_49 [ 64 ] ;
F_29 ( L_19
L_20 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_2 -> V_13 ,
F_25 ( V_48 , sizeof( V_48 ) , V_39 -> V_47 ,
V_39 -> V_4 ) ,
F_25 ( V_49 , sizeof( V_49 ) , V_39 -> V_2 -> V_46 ,
V_39 -> V_4 ) ) ;
return - V_44 ;
}
if ( V_39 -> V_2 -> V_40 && ( V_39 -> V_2 -> V_40 != V_40 || V_41 ) ) {
F_29 ( L_21 ,
V_21 [ V_39 -> V_4 ] , V_39 -> V_2 -> V_13 ,
V_39 -> V_2 -> V_40 ) ;
return - V_44 ;
}
if ( V_39 -> V_2 -> V_50 != NULL ) {
V_42 = V_39 -> V_2 -> V_50 ( V_39 ) ;
if ( V_42 < 0 )
return V_42 ;
else if ( V_42 > 0 )
return - V_51 ;
}
return 0 ;
}
int F_43 ( const struct V_1 * V_2 )
{
T_5 V_65 = V_2 -> V_66 ? : V_2 -> V_83 ;
return F_28 ( V_2 -> V_83 ) - F_37 ( V_65 ) ;
}
void F_44 ( struct V_84 * V_22 , void * * V_68 ,
unsigned int * V_28 )
{
const struct V_1 * V_2 = V_22 -> V_69 . V_70 . V_2 ;
struct V_85 * V_86 = (struct V_85 * ) V_22 ;
int V_73 , V_74 = F_43 ( V_2 ) ;
T_5 V_87 = V_86 -> V_69 . V_76 . V_88 ;
V_22 = * V_68 ;
memcpy ( V_22 , V_86 , sizeof( * V_86 ) ) ;
if ( V_2 -> V_78 )
V_2 -> V_78 ( V_22 -> V_79 , V_86 -> V_79 ) ;
else
memcpy ( V_22 -> V_79 , V_86 -> V_79 , V_87 - sizeof( * V_86 ) ) ;
V_73 = F_28 ( V_2 -> V_83 ) - V_2 -> V_83 ;
if ( V_73 > 0 )
memset ( V_22 -> V_79 + V_2 -> V_83 , 0 , V_73 ) ;
V_87 += V_74 ;
V_22 -> V_69 . V_76 . V_88 = V_87 ;
* V_28 += V_74 ;
* V_68 += V_87 ;
}
int F_45 ( const struct V_84 * V_22 ,
void T_6 * * V_68 , unsigned int * V_28 )
{
const struct V_1 * V_2 = V_22 -> V_69 . V_70 . V_2 ;
struct V_85 T_6 * V_86 = * V_68 ;
int V_74 = F_43 ( V_2 ) ;
T_5 V_87 = V_22 -> V_69 . V_76 . V_88 - V_74 ;
if ( F_40 ( V_86 , V_22 , sizeof( * V_86 ) ) ||
F_41 ( V_87 , & V_86 -> V_69 . V_76 . V_88 ) ||
F_40 ( V_86 -> V_69 . V_76 . V_13 , V_22 -> V_69 . V_70 . V_2 -> V_13 ,
strlen ( V_22 -> V_69 . V_70 . V_2 -> V_13 ) + 1 ) )
return - V_80 ;
if ( V_2 -> V_81 ) {
if ( V_2 -> V_81 ( ( void T_6 * ) V_86 -> V_79 , V_22 -> V_79 ) )
return - V_80 ;
} else {
if ( F_40 ( V_86 -> V_79 , V_22 -> V_79 , V_87 - sizeof( * V_86 ) ) )
return - V_80 ;
}
* V_28 -= V_74 ;
* V_68 += V_87 ;
return 0 ;
}
struct V_89 * F_46 ( unsigned int V_28 )
{
struct V_89 * V_90 = NULL ;
T_4 V_91 = sizeof( * V_90 ) + V_28 ;
if ( V_91 < sizeof( * V_90 ) )
return NULL ;
if ( ( F_47 ( V_28 ) >> V_92 ) + 2 > V_93 )
return NULL ;
if ( V_91 <= ( V_94 << V_95 ) )
V_90 = F_48 ( V_91 , V_96 | V_97 | V_98 ) ;
if ( ! V_90 ) {
V_90 = F_31 ( V_91 ) ;
if ( ! V_90 )
return NULL ;
}
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
V_90 -> V_28 = V_28 ;
return V_90 ;
}
void F_49 ( struct V_89 * V_90 )
{
int V_99 ;
if ( V_90 -> V_100 != NULL ) {
F_50 (cpu)
F_51 ( V_90 -> V_100 [ V_99 ] ) ;
F_51 ( V_90 -> V_100 ) ;
}
F_51 ( V_90 ) ;
}
struct V_101 * F_52 ( struct V_102 * V_102 , T_1 V_3 ,
const char * V_13 )
{
struct V_101 * V_22 , * V_103 = NULL ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
F_14 (t, &net->xt.tables[af], list)
if ( strcmp ( V_22 -> V_13 , V_13 ) == 0 && F_15 ( V_22 -> V_17 ) )
return V_22 ;
if ( V_102 == & V_104 )
goto V_105;
F_14 (t, &init_net.xt.tables[af], list) {
if ( strcmp ( V_22 -> V_13 , V_13 ) )
continue;
if ( ! F_15 ( V_22 -> V_17 ) )
return NULL ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
if ( V_22 -> V_106 ( V_102 ) != 0 ) {
F_53 ( V_22 -> V_17 ) ;
return NULL ;
}
V_103 = V_22 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
break;
}
if ( ! V_103 )
goto V_105;
F_14 (t, &net->xt.tables[af], list)
if ( strcmp ( V_22 -> V_13 , V_13 ) == 0 )
return V_22 ;
F_53 ( V_103 -> V_17 ) ;
V_105:
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
return NULL ;
}
void F_54 ( struct V_101 * V_45 )
{
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
}
void F_55 ( T_1 V_3 )
{
F_2 ( & V_5 [ V_3 ] . V_107 ) ;
}
void F_56 ( T_1 V_3 )
{
F_4 ( & V_5 [ V_3 ] . V_107 ) ;
}
static int F_57 ( struct V_89 * V_9 )
{
unsigned int V_28 ;
int V_99 ;
V_28 = sizeof( void * * ) * V_108 ;
if ( V_28 > V_94 )
V_9 -> V_100 = F_58 ( V_28 ) ;
else
V_9 -> V_100 = F_59 ( V_28 , V_96 ) ;
if ( V_9 -> V_100 == NULL )
return - V_59 ;
if ( V_9 -> V_109 == 0 )
return 0 ;
V_28 = sizeof( void * ) * V_9 -> V_109 * 2u ;
F_50 (cpu) {
if ( V_28 > V_94 )
V_9 -> V_100 [ V_99 ] = F_60 ( V_28 ,
F_61 ( V_99 ) ) ;
else
V_9 -> V_100 [ V_99 ] = F_62 ( V_28 ,
V_96 , F_61 ( V_99 ) ) ;
if ( V_9 -> V_100 [ V_99 ] == NULL )
return - V_59 ;
}
return 0 ;
}
struct V_89 *
F_63 ( struct V_101 * V_45 ,
unsigned int V_110 ,
struct V_89 * V_111 ,
int * error )
{
struct V_89 * V_112 ;
int V_42 ;
V_42 = F_57 ( V_111 ) ;
if ( V_42 < 0 ) {
* error = V_42 ;
return NULL ;
}
F_64 () ;
V_112 = V_45 -> V_112 ;
if ( V_110 != V_112 -> V_57 ) {
F_65 ( L_22 ,
V_110 , V_112 -> V_57 ) ;
F_66 () ;
* error = - V_113 ;
return NULL ;
}
V_111 -> V_114 = V_112 -> V_114 ;
F_67 () ;
V_45 -> V_112 = V_111 ;
F_66 () ;
#ifdef F_68
if ( V_115 ) {
struct V_116 * V_117 ;
V_117 = F_69 ( V_118 -> V_119 , V_96 ,
V_120 ) ;
if ( V_117 ) {
F_70 ( V_117 , L_23 ,
V_45 -> V_13 , V_45 -> V_3 ,
V_112 -> V_57 ) ;
F_71 ( V_117 ) ;
}
}
#endif
return V_112 ;
}
struct V_101 * F_72 ( struct V_102 * V_102 ,
const struct V_101 * V_121 ,
struct V_89 * V_122 ,
struct V_89 * V_111 )
{
int V_42 ;
struct V_89 * V_112 ;
struct V_101 * V_22 , * V_45 ;
V_45 = F_73 ( V_121 , sizeof( struct V_101 ) , V_96 ) ;
if ( ! V_45 ) {
V_42 = - V_59 ;
goto V_105;
}
F_2 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
F_14 (t, &net->xt.tables[table->af], list) {
if ( strcmp ( V_22 -> V_13 , V_45 -> V_13 ) == 0 ) {
V_42 = - V_123 ;
goto V_124;
}
}
V_45 -> V_112 = V_122 ;
if ( ! F_63 ( V_45 , 0 , V_111 , & V_42 ) )
goto V_124;
V_112 = V_45 -> V_112 ;
F_65 ( L_24 , V_112 -> V_57 ) ;
V_112 -> V_114 = V_112 -> V_57 ;
F_3 ( & V_45 -> V_7 , & V_102 -> V_5 . V_125 [ V_45 -> V_3 ] ) ;
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
return V_45 ;
V_124:
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
F_74 ( V_45 ) ;
V_105:
return F_16 ( V_42 ) ;
}
void * F_75 ( struct V_101 * V_45 )
{
struct V_89 * V_112 ;
F_2 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
V_112 = V_45 -> V_112 ;
F_6 ( & V_45 -> V_7 ) ;
F_4 ( & V_5 [ V_45 -> V_3 ] . V_6 ) ;
F_74 ( V_45 ) ;
return V_112 ;
}
static void * F_76 ( struct V_126 * V_127 , T_7 * V_128 )
{
struct V_129 * V_130 = V_127 -> V_112 ;
struct V_102 * V_102 = F_77 ( V_127 ) ;
T_1 V_3 = V_130 -> V_3 ;
F_2 ( & V_5 [ V_3 ] . V_6 ) ;
return F_78 ( & V_102 -> V_5 . V_125 [ V_3 ] , * V_128 ) ;
}
static void * F_79 ( struct V_126 * V_127 , void * V_131 , T_7 * V_128 )
{
struct V_129 * V_130 = V_127 -> V_112 ;
struct V_102 * V_102 = F_77 ( V_127 ) ;
T_1 V_3 = V_130 -> V_3 ;
return F_80 ( V_131 , & V_102 -> V_5 . V_125 [ V_3 ] , V_128 ) ;
}
static void F_81 ( struct V_126 * V_127 , void * V_131 )
{
struct V_129 * V_130 = V_127 -> V_112 ;
T_1 V_3 = V_130 -> V_3 ;
F_4 ( & V_5 [ V_3 ] . V_6 ) ;
}
static int F_82 ( struct V_126 * V_127 , void * V_131 )
{
struct V_101 * V_45 = F_83 ( V_131 , struct V_101 , V_7 ) ;
if ( * V_45 -> V_13 )
F_84 ( V_127 , L_25 , V_45 -> V_13 ) ;
return 0 ;
}
static int F_85 ( struct V_132 * V_132 , struct V_133 * V_133 )
{
int V_42 ;
struct V_129 * V_130 ;
V_42 = F_86 ( V_132 , V_133 , & V_134 ,
sizeof( struct V_129 ) ) ;
if ( ! V_42 ) {
V_130 = ( (struct V_126 * ) V_133 -> V_135 ) -> V_112 ;
V_130 -> V_3 = ( unsigned long ) F_87 ( V_132 ) ;
}
return V_42 ;
}
static void * F_88 ( struct V_126 * V_127 , void * V_131 , T_7 * V_136 ,
bool V_137 )
{
static const T_3 V_138 [] = {
[ V_139 ] = V_140 ,
[ V_140 ] = V_141 ,
} ;
struct V_142 * V_143 = V_127 -> V_112 ;
switch ( V_143 -> V_144 ) {
case V_145 :
V_143 -> V_144 = V_139 ;
F_2 ( & V_5 [ V_19 ] . V_6 ) ;
V_143 -> V_146 = V_143 -> V_147 = V_137 ?
& V_5 [ V_19 ] . V_2 : & V_5 [ V_19 ] . V_12 ;
break;
case V_139 :
V_143 -> V_147 = V_143 -> V_147 -> V_148 ;
if ( V_143 -> V_147 != V_143 -> V_146 )
break;
F_4 ( & V_5 [ V_19 ] . V_6 ) ;
F_2 ( & V_5 [ V_143 -> V_20 ] . V_6 ) ;
V_143 -> V_146 = V_143 -> V_147 = V_137 ?
& V_5 [ V_143 -> V_20 ] . V_2 : & V_5 [ V_143 -> V_20 ] . V_12 ;
V_143 -> V_144 = V_138 [ V_143 -> V_144 ] ;
break;
case V_140 :
V_143 -> V_147 = V_143 -> V_147 -> V_148 ;
if ( V_143 -> V_147 != V_143 -> V_146 )
break;
default:
return NULL ;
}
if ( V_136 != NULL )
++ * V_136 ;
return V_143 ;
}
static void * F_89 ( struct V_126 * V_127 , T_7 * V_128 ,
bool V_137 )
{
struct V_142 * V_143 = V_127 -> V_112 ;
unsigned int V_149 ;
V_143 -> V_144 = V_145 ;
for ( V_149 = 0 ; V_149 < * V_128 ; ++ V_149 )
if ( F_88 ( V_127 , NULL , NULL , V_137 ) == NULL )
return NULL ;
return V_143 ;
}
static void F_90 ( struct V_126 * V_127 , void * V_131 )
{
struct V_142 * V_143 = V_127 -> V_112 ;
switch ( V_143 -> V_144 ) {
case V_139 :
F_4 ( & V_5 [ V_19 ] . V_6 ) ;
break;
case V_140 :
F_4 ( & V_5 [ V_143 -> V_20 ] . V_6 ) ;
break;
}
}
static void * F_91 ( struct V_126 * V_127 , T_7 * V_128 )
{
return F_89 ( V_127 , V_128 , false ) ;
}
static void * F_92 ( struct V_126 * V_127 , void * V_131 , T_7 * V_136 )
{
return F_88 ( V_127 , V_131 , V_136 , false ) ;
}
static int F_93 ( struct V_126 * V_127 , void * V_131 )
{
const struct V_142 * V_143 = V_127 -> V_112 ;
const struct V_11 * V_12 ;
switch ( V_143 -> V_144 ) {
case V_139 :
case V_140 :
if ( V_143 -> V_147 == V_143 -> V_146 )
return 0 ;
V_12 = F_83 ( V_143 -> V_147 , struct V_11 , V_7 ) ;
if ( * V_12 -> V_13 )
F_84 ( V_127 , L_25 , V_12 -> V_13 ) ;
}
return 0 ;
}
static int F_94 ( struct V_132 * V_132 , struct V_133 * V_133 )
{
struct V_142 * V_143 ;
V_143 = F_95 ( V_133 , & V_150 , sizeof( * V_143 ) ) ;
if ( ! V_143 )
return - V_59 ;
V_143 -> V_20 = ( unsigned long ) F_87 ( V_132 ) ;
return 0 ;
}
static void * F_96 ( struct V_126 * V_127 , T_7 * V_128 )
{
return F_89 ( V_127 , V_128 , true ) ;
}
static void * F_97 ( struct V_126 * V_127 , void * V_131 , T_7 * V_136 )
{
return F_88 ( V_127 , V_131 , V_136 , true ) ;
}
static int F_98 ( struct V_126 * V_127 , void * V_131 )
{
const struct V_142 * V_143 = V_127 -> V_112 ;
const struct V_1 * V_2 ;
switch ( V_143 -> V_144 ) {
case V_139 :
case V_140 :
if ( V_143 -> V_147 == V_143 -> V_146 )
return 0 ;
V_2 = F_83 ( V_143 -> V_147 , struct V_1 , V_7 ) ;
if ( * V_2 -> V_13 )
F_84 ( V_127 , L_25 , V_2 -> V_13 ) ;
}
return 0 ;
}
static int F_99 ( struct V_132 * V_132 , struct V_133 * V_133 )
{
struct V_142 * V_143 ;
V_143 = F_95 ( V_133 , & V_151 , sizeof( * V_143 ) ) ;
if ( ! V_143 )
return - V_59 ;
V_143 -> V_20 = ( unsigned long ) F_87 ( V_132 ) ;
return 0 ;
}
struct V_152 *
F_100 ( const struct V_101 * V_45 , T_8 * V_153 )
{
unsigned int V_47 = V_45 -> V_154 ;
T_3 V_9 , V_155 = F_101 ( V_47 ) ;
T_3 V_156 ;
struct V_152 * V_157 ;
V_157 = F_48 ( sizeof( * V_157 ) * V_155 , V_96 ) ;
if ( V_157 == NULL )
return F_16 ( - V_59 ) ;
for ( V_9 = 0 , V_156 = 0 ; V_9 < V_155 && V_47 != 0 ;
V_47 >>= 1 , ++ V_156 ) {
if ( ! ( V_47 & 1 ) )
continue;
V_157 [ V_9 ] . V_158 = V_153 ;
V_157 [ V_9 ] . V_159 = V_45 -> V_3 ;
V_157 [ V_9 ] . V_156 = V_156 ;
V_157 [ V_9 ] . V_160 = V_45 -> V_160 ;
++ V_9 ;
}
return V_157 ;
}
int F_102 ( struct V_102 * V_102 , T_1 V_3 )
{
#ifdef F_103
char V_27 [ V_161 ] ;
struct V_162 * V_163 ;
T_9 V_164 ;
T_10 V_165 ;
#endif
if ( V_3 >= F_26 ( V_21 ) )
return - V_44 ;
#ifdef F_103
V_164 = F_104 ( V_102 -> V_166 , 0 ) ;
V_165 = F_105 ( V_102 -> V_166 , 0 ) ;
F_106 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_107 ( V_27 , V_167 , sizeof( V_27 ) ) ;
V_163 = F_108 ( V_27 , 0440 , V_102 -> V_168 , & V_169 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_163 )
goto V_105;
if ( F_109 ( V_164 ) && F_110 ( V_165 ) )
F_111 ( V_163 , V_164 , V_165 ) ;
F_106 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_107 ( V_27 , V_170 , sizeof( V_27 ) ) ;
V_163 = F_108 ( V_27 , 0440 , V_102 -> V_168 , & V_171 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_163 )
goto V_172;
if ( F_109 ( V_164 ) && F_110 ( V_165 ) )
F_111 ( V_163 , V_164 , V_165 ) ;
F_106 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_107 ( V_27 , V_173 , sizeof( V_27 ) ) ;
V_163 = F_108 ( V_27 , 0440 , V_102 -> V_168 , & V_174 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_163 )
goto V_175;
if ( F_109 ( V_164 ) && F_110 ( V_165 ) )
F_111 ( V_163 , V_164 , V_165 ) ;
#endif
return 0 ;
#ifdef F_103
V_175:
F_106 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_107 ( V_27 , V_170 , sizeof( V_27 ) ) ;
F_112 ( V_27 , V_102 -> V_168 ) ;
V_172:
F_106 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_107 ( V_27 , V_167 , sizeof( V_27 ) ) ;
F_112 ( V_27 , V_102 -> V_168 ) ;
V_105:
return - 1 ;
#endif
}
void F_113 ( struct V_102 * V_102 , T_1 V_3 )
{
#ifdef F_103
char V_27 [ V_161 ] ;
F_106 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_107 ( V_27 , V_167 , sizeof( V_27 ) ) ;
F_112 ( V_27 , V_102 -> V_168 ) ;
F_106 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_107 ( V_27 , V_173 , sizeof( V_27 ) ) ;
F_112 ( V_27 , V_102 -> V_168 ) ;
F_106 ( V_27 , V_21 [ V_3 ] , sizeof( V_27 ) ) ;
F_107 ( V_27 , V_170 , sizeof( V_27 ) ) ;
F_112 ( V_27 , V_102 -> V_168 ) ;
#endif
}
static int T_11 F_114 ( struct V_102 * V_102 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_176 ; V_9 ++ )
F_115 ( & V_102 -> V_5 . V_125 [ V_9 ] ) ;
return 0 ;
}
static int T_12 F_116 ( void )
{
unsigned int V_9 ;
int V_177 ;
F_50 (i) {
F_117 ( & F_118 ( V_178 , V_9 ) ) ;
}
V_5 = F_48 ( sizeof( struct V_54 ) * V_176 , V_96 ) ;
if ( ! V_5 )
return - V_59 ;
for ( V_9 = 0 ; V_9 < V_176 ; V_9 ++ ) {
F_119 ( & V_5 [ V_9 ] . V_6 ) ;
#ifdef F_120
F_119 ( & V_5 [ V_9 ] . V_107 ) ;
V_5 [ V_9 ] . V_56 = NULL ;
#endif
F_115 ( & V_5 [ V_9 ] . V_2 ) ;
F_115 ( & V_5 [ V_9 ] . V_12 ) ;
}
V_177 = F_121 ( & V_179 ) ;
if ( V_177 < 0 )
F_74 ( V_5 ) ;
return V_177 ;
}
static void T_13 F_122 ( void )
{
F_123 ( & V_179 ) ;
F_74 ( V_5 ) ;
}
