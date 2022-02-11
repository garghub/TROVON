int
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 ;
int V_5 ;
V_5 = F_2 ( & V_6 [ V_3 ] . V_7 ) ;
if ( V_5 != 0 )
return V_5 ;
F_3 ( & V_2 -> V_8 , & V_6 [ V_3 ] . V_2 ) ;
F_4 ( & V_6 [ V_3 ] . V_7 ) ;
return V_5 ;
}
void
F_5 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 ;
F_6 ( & V_6 [ V_3 ] . V_7 ) ;
F_7 ( & V_2 -> V_8 ) ;
F_4 ( & V_6 [ V_3 ] . V_7 ) ;
}
int
F_8 ( struct V_1 * V_2 , unsigned int V_9 )
{
unsigned int V_10 ;
int V_11 = 0 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
V_11 = F_1 ( & V_2 [ V_10 ] ) ;
if ( V_11 )
goto V_11;
}
return V_11 ;
V_11:
if ( V_10 > 0 )
F_9 ( V_2 , V_10 ) ;
return V_11 ;
}
void
F_9 ( struct V_1 * V_2 , unsigned int V_9 )
{
while ( V_9 -- > 0 )
F_5 ( & V_2 [ V_9 ] ) ;
}
int
F_10 ( struct V_12 * V_13 )
{
T_1 V_3 = V_13 -> V_4 ;
int V_5 ;
V_5 = F_2 ( & V_6 [ V_3 ] . V_7 ) ;
if ( V_5 != 0 )
return V_5 ;
F_3 ( & V_13 -> V_8 , & V_6 [ V_3 ] . V_13 ) ;
F_4 ( & V_6 [ V_3 ] . V_7 ) ;
return V_5 ;
}
void
F_11 ( struct V_12 * V_13 )
{
T_1 V_3 = V_13 -> V_4 ;
F_6 ( & V_6 [ V_3 ] . V_7 ) ;
F_7 ( & V_13 -> V_8 ) ;
F_4 ( & V_6 [ V_3 ] . V_7 ) ;
}
int
F_12 ( struct V_12 * V_13 , unsigned int V_9 )
{
unsigned int V_10 ;
int V_11 = 0 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
V_11 = F_10 ( & V_13 [ V_10 ] ) ;
if ( V_11 )
goto V_11;
}
return V_11 ;
V_11:
if ( V_10 > 0 )
F_13 ( V_13 , V_10 ) ;
return V_11 ;
}
void
F_13 ( struct V_12 * V_13 , unsigned int V_9 )
{
while ( V_9 -- > 0 )
F_11 ( & V_13 [ V_9 ] ) ;
}
struct V_12 * F_14 ( T_2 V_3 , const char * V_14 , T_2 V_15 )
{
struct V_12 * V_16 ;
int V_11 = - V_17 ;
if ( F_2 ( & V_6 [ V_3 ] . V_7 ) != 0 )
return F_15 ( - V_18 ) ;
F_16 (m, &xt[af].match, list) {
if ( strcmp ( V_16 -> V_14 , V_14 ) == 0 ) {
if ( V_16 -> V_15 == V_15 ) {
if ( F_17 ( V_16 -> V_19 ) ) {
F_4 ( & V_6 [ V_3 ] . V_7 ) ;
return V_16 ;
}
} else
V_11 = - V_20 ;
}
}
F_4 ( & V_6 [ V_3 ] . V_7 ) ;
if ( V_3 != V_21 )
return F_14 ( V_21 , V_14 , V_15 ) ;
return F_15 ( V_11 ) ;
}
struct V_12 *
F_18 ( T_3 V_22 , const char * V_14 , T_3 V_15 )
{
struct V_12 * V_13 ;
V_13 = F_14 ( V_22 , V_14 , V_15 ) ;
if ( F_19 ( V_13 ) ) {
F_20 ( L_1 , V_23 [ V_22 ] , V_14 ) ;
V_13 = F_14 ( V_22 , V_14 , V_15 ) ;
}
return V_13 ;
}
struct V_1 * F_21 ( T_2 V_3 , const char * V_14 , T_2 V_15 )
{
struct V_1 * V_24 ;
int V_11 = - V_17 ;
if ( F_2 ( & V_6 [ V_3 ] . V_7 ) != 0 )
return F_15 ( - V_18 ) ;
F_16 (t, &xt[af].target, list) {
if ( strcmp ( V_24 -> V_14 , V_14 ) == 0 ) {
if ( V_24 -> V_15 == V_15 ) {
if ( F_17 ( V_24 -> V_19 ) ) {
F_4 ( & V_6 [ V_3 ] . V_7 ) ;
return V_24 ;
}
} else
V_11 = - V_20 ;
}
}
F_4 ( & V_6 [ V_3 ] . V_7 ) ;
if ( V_3 != V_21 )
return F_21 ( V_21 , V_14 , V_15 ) ;
return F_15 ( V_11 ) ;
}
struct V_1 * F_22 ( T_2 V_3 , const char * V_14 , T_2 V_15 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_3 , V_14 , V_15 ) ;
if ( F_19 ( V_2 ) ) {
F_20 ( L_1 , V_23 [ V_3 ] , V_14 ) ;
V_2 = F_21 ( V_3 , V_14 , V_15 ) ;
}
return V_2 ;
}
static int F_23 ( T_2 V_3 , const char * V_14 , T_2 V_15 , int * V_25 )
{
const struct V_12 * V_16 ;
int V_26 = 0 ;
F_16 (m, &xt[af].match, list) {
if ( strcmp ( V_16 -> V_14 , V_14 ) == 0 ) {
if ( V_16 -> V_15 > * V_25 )
* V_25 = V_16 -> V_15 ;
if ( V_16 -> V_15 == V_15 )
V_26 = 1 ;
}
}
if ( V_3 != V_21 && ! V_26 )
return F_23 ( V_21 , V_14 , V_15 , V_25 ) ;
return V_26 ;
}
static int F_24 ( T_2 V_3 , const char * V_14 , T_2 V_15 , int * V_25 )
{
const struct V_1 * V_24 ;
int V_26 = 0 ;
F_16 (t, &xt[af].target, list) {
if ( strcmp ( V_24 -> V_14 , V_14 ) == 0 ) {
if ( V_24 -> V_15 > * V_25 )
* V_25 = V_24 -> V_15 ;
if ( V_24 -> V_15 == V_15 )
V_26 = 1 ;
}
}
if ( V_3 != V_21 && ! V_26 )
return F_24 ( V_21 , V_14 , V_15 , V_25 ) ;
return V_26 ;
}
int F_25 ( T_2 V_3 , const char * V_14 , T_2 V_15 , int V_2 ,
int * V_11 )
{
int V_26 , V_27 = - 1 ;
if ( F_2 ( & V_6 [ V_3 ] . V_7 ) != 0 ) {
* V_11 = - V_18 ;
return 1 ;
}
if ( V_2 == 1 )
V_26 = F_24 ( V_3 , V_14 , V_15 , & V_27 ) ;
else
V_26 = F_23 ( V_3 , V_14 , V_15 , & V_27 ) ;
F_4 ( & V_6 [ V_3 ] . V_7 ) ;
if ( V_27 == - 1 ) {
* V_11 = - V_17 ;
return 0 ;
}
* V_11 = V_27 ;
if ( ! V_26 )
* V_11 = - V_28 ;
return 1 ;
}
static char * F_26 ( char * V_29 , T_4 V_30 , unsigned int V_31 )
{
static const char * const V_32 [] = {
L_2 , L_3 , L_4 ,
L_5 , L_6 , L_7 ,
} ;
unsigned int V_10 ;
char * V_33 = V_29 ;
bool V_34 = false ;
int V_35 ;
* V_33 = '\0' ;
for ( V_10 = 0 ; V_10 < F_27 ( V_32 ) ; ++ V_10 ) {
if ( ! ( V_31 & ( 1 << V_10 ) ) )
continue;
V_35 = snprintf ( V_33 , V_30 , L_8 , V_34 ? L_9 : L_10 , V_32 [ V_10 ] ) ;
if ( V_35 > 0 ) {
V_30 -= V_35 ;
V_33 += V_35 ;
}
V_34 = true ;
}
return V_29 ;
}
int F_28 ( struct V_36 * V_37 ,
unsigned int V_30 , T_1 V_38 , bool V_39 )
{
int V_5 ;
if ( F_29 ( V_37 -> V_13 -> V_40 ) != V_30 &&
V_37 -> V_13 -> V_40 != - 1 ) {
F_30 ( L_11
L_12 ,
V_23 [ V_37 -> V_4 ] , V_37 -> V_13 -> V_14 ,
V_37 -> V_13 -> V_15 ,
F_29 ( V_37 -> V_13 -> V_40 ) , V_30 ) ;
return - V_41 ;
}
if ( V_37 -> V_13 -> V_42 != NULL &&
strcmp ( V_37 -> V_13 -> V_42 , V_37 -> V_42 ) != 0 ) {
F_30 ( L_13 ,
V_23 [ V_37 -> V_4 ] , V_37 -> V_13 -> V_14 ,
V_37 -> V_13 -> V_42 , V_37 -> V_42 ) ;
return - V_41 ;
}
if ( V_37 -> V_13 -> V_43 && ( V_37 -> V_44 & ~ V_37 -> V_13 -> V_43 ) != 0 ) {
char V_45 [ 64 ] , V_46 [ 64 ] ;
F_30 ( L_14
L_15 ,
V_23 [ V_37 -> V_4 ] , V_37 -> V_13 -> V_14 ,
F_26 ( V_45 , sizeof( V_45 ) , V_37 -> V_44 ) ,
F_26 ( V_46 , sizeof( V_46 ) , V_37 -> V_13 -> V_43 ) ) ;
return - V_41 ;
}
if ( V_37 -> V_13 -> V_38 && ( V_37 -> V_13 -> V_38 != V_38 || V_39 ) ) {
F_30 ( L_16 ,
V_23 [ V_37 -> V_4 ] , V_37 -> V_13 -> V_14 ,
V_37 -> V_13 -> V_38 ) ;
return - V_41 ;
}
if ( V_37 -> V_13 -> V_47 != NULL ) {
V_5 = V_37 -> V_13 -> V_47 ( V_37 ) ;
if ( V_5 < 0 )
return V_5 ;
else if ( V_5 > 0 )
return - V_48 ;
}
return 0 ;
}
int F_31 ( T_1 V_3 , unsigned int V_49 , int V_50 )
{
struct V_51 * V_52 = & V_6 [ V_3 ] ;
if ( ! V_52 -> V_53 ) {
if ( ! V_52 -> V_54 )
return - V_41 ;
V_52 -> V_53 = F_32 ( sizeof( struct V_55 ) * V_52 -> V_54 ) ;
if ( ! V_52 -> V_53 )
return - V_56 ;
V_52 -> V_57 = 0 ;
}
if ( V_52 -> V_57 >= V_52 -> V_54 )
return - V_41 ;
if ( V_52 -> V_57 )
V_50 += V_52 -> V_53 [ V_52 -> V_57 - 1 ] . V_50 ;
V_52 -> V_53 [ V_52 -> V_57 ] . V_49 = V_49 ;
V_52 -> V_53 [ V_52 -> V_57 ] . V_50 = V_50 ;
V_52 -> V_57 ++ ;
return 0 ;
}
void F_33 ( T_1 V_3 )
{
if ( V_6 [ V_3 ] . V_53 ) {
F_34 ( V_6 [ V_3 ] . V_53 ) ;
V_6 [ V_3 ] . V_53 = NULL ;
V_6 [ V_3 ] . V_54 = 0 ;
V_6 [ V_3 ] . V_57 = 0 ;
}
}
int F_35 ( T_1 V_3 , unsigned int V_49 )
{
struct V_55 * V_58 = V_6 [ V_3 ] . V_53 ;
int V_59 , V_60 = 0 , V_61 = V_6 [ V_3 ] . V_57 - 1 ;
while ( V_60 <= V_61 ) {
V_59 = ( V_60 + V_61 ) >> 1 ;
if ( V_49 > V_58 [ V_59 ] . V_49 )
V_60 = V_59 + 1 ;
else if ( V_49 < V_58 [ V_59 ] . V_49 )
V_61 = V_59 - 1 ;
else
return V_59 ? V_58 [ V_59 - 1 ] . V_50 : 0 ;
}
return V_60 ? V_58 [ V_60 - 1 ] . V_50 : 0 ;
}
void F_36 ( T_1 V_3 , unsigned int V_54 )
{
V_6 [ V_3 ] . V_54 = V_54 ;
V_6 [ V_3 ] . V_57 = 0 ;
}
int F_37 ( const struct V_12 * V_13 )
{
T_5 V_62 = V_13 -> V_63 ? : V_13 -> V_40 ;
return F_29 ( V_13 -> V_40 ) - F_38 ( V_62 ) ;
}
int F_39 ( struct V_64 * V_16 , void * * V_65 ,
unsigned int * V_30 )
{
const struct V_12 * V_13 = V_16 -> V_66 . V_67 . V_13 ;
struct V_68 * V_69 = (struct V_68 * ) V_16 ;
int V_70 , V_71 = F_37 ( V_13 ) ;
T_5 V_72 = V_69 -> V_66 . V_73 . V_74 ;
V_16 = * V_65 ;
memcpy ( V_16 , V_69 , sizeof( * V_69 ) ) ;
if ( V_13 -> V_75 )
V_13 -> V_75 ( V_16 -> V_76 , V_69 -> V_76 ) ;
else
memcpy ( V_16 -> V_76 , V_69 -> V_76 , V_72 - sizeof( * V_69 ) ) ;
V_70 = F_29 ( V_13 -> V_40 ) - V_13 -> V_40 ;
if ( V_70 > 0 )
memset ( V_16 -> V_76 + V_13 -> V_40 , 0 , V_70 ) ;
V_72 += V_71 ;
V_16 -> V_66 . V_73 . V_74 = V_72 ;
* V_30 += V_71 ;
* V_65 += V_72 ;
return 0 ;
}
int F_40 ( const struct V_64 * V_16 ,
void T_6 * * V_65 , unsigned int * V_30 )
{
const struct V_12 * V_13 = V_16 -> V_66 . V_67 . V_13 ;
struct V_68 T_6 * V_69 = * V_65 ;
int V_71 = F_37 ( V_13 ) ;
T_5 V_72 = V_16 -> V_66 . V_73 . V_74 - V_71 ;
if ( F_41 ( V_69 , V_16 , sizeof( * V_69 ) ) ||
F_42 ( V_72 , & V_69 -> V_66 . V_73 . V_74 ) ||
F_41 ( V_69 -> V_66 . V_73 . V_14 , V_16 -> V_66 . V_67 . V_13 -> V_14 ,
strlen ( V_16 -> V_66 . V_67 . V_13 -> V_14 ) + 1 ) )
return - V_77 ;
if ( V_13 -> V_78 ) {
if ( V_13 -> V_78 ( ( void T_6 * ) V_69 -> V_76 , V_16 -> V_76 ) )
return - V_77 ;
} else {
if ( F_41 ( V_69 -> V_76 , V_16 -> V_76 , V_72 - sizeof( * V_69 ) ) )
return - V_77 ;
}
* V_30 -= V_71 ;
* V_65 += V_72 ;
return 0 ;
}
int F_43 ( struct V_79 * V_37 ,
unsigned int V_30 , T_1 V_38 , bool V_39 )
{
int V_5 ;
if ( F_29 ( V_37 -> V_2 -> V_80 ) != V_30 ) {
F_30 ( L_17
L_12 ,
V_23 [ V_37 -> V_4 ] , V_37 -> V_2 -> V_14 ,
V_37 -> V_2 -> V_15 ,
F_29 ( V_37 -> V_2 -> V_80 ) , V_30 ) ;
return - V_41 ;
}
if ( V_37 -> V_2 -> V_42 != NULL &&
strcmp ( V_37 -> V_2 -> V_42 , V_37 -> V_42 ) != 0 ) {
F_30 ( L_18 ,
V_23 [ V_37 -> V_4 ] , V_37 -> V_2 -> V_14 ,
V_37 -> V_2 -> V_42 , V_37 -> V_42 ) ;
return - V_41 ;
}
if ( V_37 -> V_2 -> V_43 && ( V_37 -> V_44 & ~ V_37 -> V_2 -> V_43 ) != 0 ) {
char V_45 [ 64 ] , V_46 [ 64 ] ;
F_30 ( L_19
L_20 ,
V_23 [ V_37 -> V_4 ] , V_37 -> V_2 -> V_14 ,
F_26 ( V_45 , sizeof( V_45 ) , V_37 -> V_44 ) ,
F_26 ( V_46 , sizeof( V_46 ) , V_37 -> V_2 -> V_43 ) ) ;
return - V_41 ;
}
if ( V_37 -> V_2 -> V_38 && ( V_37 -> V_2 -> V_38 != V_38 || V_39 ) ) {
F_30 ( L_21 ,
V_23 [ V_37 -> V_4 ] , V_37 -> V_2 -> V_14 ,
V_37 -> V_2 -> V_38 ) ;
return - V_41 ;
}
if ( V_37 -> V_2 -> V_47 != NULL ) {
V_5 = V_37 -> V_2 -> V_47 ( V_37 ) ;
if ( V_5 < 0 )
return V_5 ;
else if ( V_5 > 0 )
return - V_48 ;
}
return 0 ;
}
int F_44 ( const struct V_1 * V_2 )
{
T_5 V_62 = V_2 -> V_63 ? : V_2 -> V_80 ;
return F_29 ( V_2 -> V_80 ) - F_38 ( V_62 ) ;
}
void F_45 ( struct V_81 * V_24 , void * * V_65 ,
unsigned int * V_30 )
{
const struct V_1 * V_2 = V_24 -> V_66 . V_67 . V_2 ;
struct V_82 * V_83 = (struct V_82 * ) V_24 ;
int V_70 , V_71 = F_44 ( V_2 ) ;
T_5 V_84 = V_83 -> V_66 . V_73 . V_85 ;
V_24 = * V_65 ;
memcpy ( V_24 , V_83 , sizeof( * V_83 ) ) ;
if ( V_2 -> V_75 )
V_2 -> V_75 ( V_24 -> V_76 , V_83 -> V_76 ) ;
else
memcpy ( V_24 -> V_76 , V_83 -> V_76 , V_84 - sizeof( * V_83 ) ) ;
V_70 = F_29 ( V_2 -> V_80 ) - V_2 -> V_80 ;
if ( V_70 > 0 )
memset ( V_24 -> V_76 + V_2 -> V_80 , 0 , V_70 ) ;
V_84 += V_71 ;
V_24 -> V_66 . V_73 . V_85 = V_84 ;
* V_30 += V_71 ;
* V_65 += V_84 ;
}
int F_46 ( const struct V_81 * V_24 ,
void T_6 * * V_65 , unsigned int * V_30 )
{
const struct V_1 * V_2 = V_24 -> V_66 . V_67 . V_2 ;
struct V_82 T_6 * V_83 = * V_65 ;
int V_71 = F_44 ( V_2 ) ;
T_5 V_84 = V_24 -> V_66 . V_73 . V_85 - V_71 ;
if ( F_41 ( V_83 , V_24 , sizeof( * V_83 ) ) ||
F_42 ( V_84 , & V_83 -> V_66 . V_73 . V_85 ) ||
F_41 ( V_83 -> V_66 . V_73 . V_14 , V_24 -> V_66 . V_67 . V_2 -> V_14 ,
strlen ( V_24 -> V_66 . V_67 . V_2 -> V_14 ) + 1 ) )
return - V_77 ;
if ( V_2 -> V_78 ) {
if ( V_2 -> V_78 ( ( void T_6 * ) V_83 -> V_76 , V_24 -> V_76 ) )
return - V_77 ;
} else {
if ( F_41 ( V_83 -> V_76 , V_24 -> V_76 , V_84 - sizeof( * V_83 ) ) )
return - V_77 ;
}
* V_30 -= V_71 ;
* V_65 += V_84 ;
return 0 ;
}
struct V_86 * F_47 ( unsigned int V_30 )
{
struct V_86 * V_87 ;
int V_88 ;
if ( ( F_48 ( V_30 ) >> V_89 ) + 2 > V_90 )
return NULL ;
V_87 = F_49 ( V_91 , V_92 ) ;
if ( ! V_87 )
return NULL ;
V_87 -> V_30 = V_30 ;
F_50 (cpu) {
if ( V_30 <= V_93 )
V_87 -> V_94 [ V_88 ] = F_51 ( V_30 ,
V_92 ,
F_52 ( V_88 ) ) ;
else
V_87 -> V_94 [ V_88 ] = F_53 ( V_30 ,
F_52 ( V_88 ) ) ;
if ( V_87 -> V_94 [ V_88 ] == NULL ) {
F_54 ( V_87 ) ;
return NULL ;
}
}
return V_87 ;
}
void F_54 ( struct V_86 * V_95 )
{
int V_88 ;
F_50 (cpu) {
if ( V_95 -> V_30 <= V_93 )
F_55 ( V_95 -> V_94 [ V_88 ] ) ;
else
F_34 ( V_95 -> V_94 [ V_88 ] ) ;
}
if ( V_95 -> V_96 != NULL ) {
if ( sizeof( void * ) * V_95 -> V_97 > V_93 ) {
F_50 (cpu)
F_34 ( V_95 -> V_96 [ V_88 ] ) ;
} else {
F_50 (cpu)
F_55 ( V_95 -> V_96 [ V_88 ] ) ;
}
}
if ( sizeof( void * * ) * V_98 > V_93 )
F_34 ( V_95 -> V_96 ) ;
else
F_55 ( V_95 -> V_96 ) ;
F_56 ( V_95 -> V_99 ) ;
F_55 ( V_95 ) ;
}
struct V_100 * F_57 ( struct V_101 * V_101 , T_1 V_3 ,
const char * V_14 )
{
struct V_100 * V_24 ;
if ( F_2 ( & V_6 [ V_3 ] . V_7 ) != 0 )
return F_15 ( - V_18 ) ;
F_16 (t, &net->xt.tables[af], list)
if ( strcmp ( V_24 -> V_14 , V_14 ) == 0 && F_17 ( V_24 -> V_19 ) )
return V_24 ;
F_4 ( & V_6 [ V_3 ] . V_7 ) ;
return NULL ;
}
void F_58 ( struct V_100 * V_42 )
{
F_4 ( & V_6 [ V_42 -> V_3 ] . V_7 ) ;
}
void F_59 ( T_1 V_3 )
{
F_6 ( & V_6 [ V_3 ] . V_102 ) ;
}
void F_60 ( T_1 V_3 )
{
F_4 ( & V_6 [ V_3 ] . V_102 ) ;
}
static int F_61 ( struct V_86 * V_10 )
{
unsigned int V_30 ;
int V_88 ;
V_10 -> V_99 = F_62 (unsigned int) ;
if ( V_10 -> V_99 == NULL )
return - V_56 ;
V_30 = sizeof( void * * ) * V_98 ;
if ( V_30 > V_93 )
V_10 -> V_96 = F_32 ( V_30 ) ;
else
V_10 -> V_96 = F_63 ( V_30 , V_92 ) ;
if ( V_10 -> V_96 == NULL )
return - V_56 ;
memset ( V_10 -> V_96 , 0 , V_30 ) ;
V_10 -> V_97 *= V_103 ;
V_30 = sizeof( void * ) * V_10 -> V_97 ;
F_50 (cpu) {
if ( V_30 > V_93 )
V_10 -> V_96 [ V_88 ] = F_53 ( V_30 ,
F_52 ( V_88 ) ) ;
else
V_10 -> V_96 [ V_88 ] = F_51 ( V_30 ,
V_92 , F_52 ( V_88 ) ) ;
if ( V_10 -> V_96 [ V_88 ] == NULL )
return - V_56 ;
}
return 0 ;
}
struct V_86 *
F_64 ( struct V_100 * V_42 ,
unsigned int V_104 ,
struct V_86 * V_87 ,
int * error )
{
struct V_86 * V_105 ;
int V_5 ;
V_5 = F_61 ( V_87 ) ;
if ( V_5 < 0 ) {
* error = V_5 ;
return NULL ;
}
F_65 () ;
V_105 = V_42 -> V_105 ;
if ( V_104 != V_105 -> V_54 ) {
F_66 ( L_22 ,
V_104 , V_105 -> V_54 ) ;
F_67 () ;
* error = - V_106 ;
return NULL ;
}
V_42 -> V_105 = V_87 ;
V_87 -> V_107 = V_105 -> V_107 ;
F_67 () ;
#ifdef F_68
if ( V_108 ) {
struct V_109 * V_110 ;
V_110 = F_69 ( V_111 -> V_112 , V_92 ,
V_113 ) ;
if ( V_110 ) {
F_70 ( V_110 , L_23 ,
V_42 -> V_14 , V_42 -> V_3 ,
V_105 -> V_54 ) ;
F_71 ( V_110 ) ;
}
}
#endif
return V_105 ;
}
struct V_100 * F_72 ( struct V_101 * V_101 ,
const struct V_100 * V_114 ,
struct V_86 * V_115 ,
struct V_86 * V_87 )
{
int V_5 ;
struct V_86 * V_105 ;
struct V_100 * V_24 , * V_42 ;
V_42 = F_73 ( V_114 , sizeof( struct V_100 ) , V_92 ) ;
if ( ! V_42 ) {
V_5 = - V_56 ;
goto V_116;
}
V_5 = F_2 ( & V_6 [ V_42 -> V_3 ] . V_7 ) ;
if ( V_5 != 0 )
goto V_117;
F_16 (t, &net->xt.tables[table->af], list) {
if ( strcmp ( V_24 -> V_14 , V_42 -> V_14 ) == 0 ) {
V_5 = - V_118 ;
goto V_119;
}
}
V_42 -> V_105 = V_115 ;
if ( ! F_64 ( V_42 , 0 , V_87 , & V_5 ) )
goto V_119;
V_105 = V_42 -> V_105 ;
F_66 ( L_24 , V_105 -> V_54 ) ;
V_105 -> V_107 = V_105 -> V_54 ;
F_3 ( & V_42 -> V_8 , & V_101 -> V_6 . V_120 [ V_42 -> V_3 ] ) ;
F_4 ( & V_6 [ V_42 -> V_3 ] . V_7 ) ;
return V_42 ;
V_119:
F_4 ( & V_6 [ V_42 -> V_3 ] . V_7 ) ;
V_117:
F_55 ( V_42 ) ;
V_116:
return F_15 ( V_5 ) ;
}
void * F_74 ( struct V_100 * V_42 )
{
struct V_86 * V_105 ;
F_6 ( & V_6 [ V_42 -> V_3 ] . V_7 ) ;
V_105 = V_42 -> V_105 ;
F_7 ( & V_42 -> V_8 ) ;
F_4 ( & V_6 [ V_42 -> V_3 ] . V_7 ) ;
F_55 ( V_42 ) ;
return V_105 ;
}
static void * F_75 ( struct V_121 * V_122 , T_7 * V_123 )
{
struct V_124 * V_125 = V_122 -> V_105 ;
struct V_101 * V_101 = F_76 ( V_122 ) ;
T_1 V_3 = V_125 -> V_3 ;
F_6 ( & V_6 [ V_3 ] . V_7 ) ;
return F_77 ( & V_101 -> V_6 . V_120 [ V_3 ] , * V_123 ) ;
}
static void * F_78 ( struct V_121 * V_122 , void * V_126 , T_7 * V_123 )
{
struct V_124 * V_125 = V_122 -> V_105 ;
struct V_101 * V_101 = F_76 ( V_122 ) ;
T_1 V_3 = V_125 -> V_3 ;
return F_79 ( V_126 , & V_101 -> V_6 . V_120 [ V_3 ] , V_123 ) ;
}
static void F_80 ( struct V_121 * V_122 , void * V_126 )
{
struct V_124 * V_125 = V_122 -> V_105 ;
T_1 V_3 = V_125 -> V_3 ;
F_4 ( & V_6 [ V_3 ] . V_7 ) ;
}
static int F_81 ( struct V_121 * V_122 , void * V_126 )
{
struct V_100 * V_42 = F_82 ( V_126 , struct V_100 , V_8 ) ;
if ( strlen ( V_42 -> V_14 ) )
return F_83 ( V_122 , L_25 , V_42 -> V_14 ) ;
else
return 0 ;
}
static int F_84 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
int V_5 ;
struct V_124 * V_125 ;
V_5 = F_85 ( V_127 , V_128 , & V_129 ,
sizeof( struct V_124 ) ) ;
if ( ! V_5 ) {
V_125 = ( (struct V_121 * ) V_128 -> V_130 ) -> V_105 ;
V_125 -> V_3 = ( unsigned long ) F_86 ( V_127 ) -> V_76 ;
}
return V_5 ;
}
static void * F_87 ( struct V_121 * V_122 , void * V_126 , T_7 * V_131 ,
bool V_132 )
{
static const T_3 V_133 [] = {
[ V_134 ] = V_135 ,
[ V_135 ] = V_136 ,
} ;
struct V_137 * V_138 = V_122 -> V_105 ;
switch ( V_138 -> V_139 ) {
case V_140 :
V_138 -> V_139 = V_134 ;
F_6 ( & V_6 [ V_21 ] . V_7 ) ;
V_138 -> V_141 = V_138 -> V_142 = V_132 ?
& V_6 [ V_21 ] . V_2 : & V_6 [ V_21 ] . V_13 ;
break;
case V_134 :
V_138 -> V_142 = V_138 -> V_142 -> V_143 ;
if ( V_138 -> V_142 != V_138 -> V_141 )
break;
F_4 ( & V_6 [ V_21 ] . V_7 ) ;
F_6 ( & V_6 [ V_138 -> V_22 ] . V_7 ) ;
V_138 -> V_141 = V_138 -> V_142 = V_132 ?
& V_6 [ V_138 -> V_22 ] . V_2 : & V_6 [ V_138 -> V_22 ] . V_13 ;
V_138 -> V_139 = V_133 [ V_138 -> V_139 ] ;
break;
case V_135 :
V_138 -> V_142 = V_138 -> V_142 -> V_143 ;
if ( V_138 -> V_142 != V_138 -> V_141 )
break;
default:
return NULL ;
}
if ( V_131 != NULL )
++ * V_131 ;
return V_138 ;
}
static void * F_88 ( struct V_121 * V_122 , T_7 * V_123 ,
bool V_132 )
{
struct V_137 * V_138 = V_122 -> V_105 ;
unsigned int V_144 ;
V_138 -> V_139 = V_140 ;
for ( V_144 = 0 ; V_144 < * V_123 ; ++ V_144 )
if ( F_87 ( V_122 , NULL , NULL , V_132 ) == NULL )
return NULL ;
return V_138 ;
}
static void F_89 ( struct V_121 * V_122 , void * V_126 )
{
struct V_137 * V_138 = V_122 -> V_105 ;
switch ( V_138 -> V_139 ) {
case V_134 :
F_4 ( & V_6 [ V_21 ] . V_7 ) ;
break;
case V_135 :
F_4 ( & V_6 [ V_138 -> V_22 ] . V_7 ) ;
break;
}
}
static void * F_90 ( struct V_121 * V_122 , T_7 * V_123 )
{
return F_88 ( V_122 , V_123 , false ) ;
}
static void * F_91 ( struct V_121 * V_122 , void * V_126 , T_7 * V_131 )
{
return F_87 ( V_122 , V_126 , V_131 , false ) ;
}
static int F_92 ( struct V_121 * V_122 , void * V_126 )
{
const struct V_137 * V_138 = V_122 -> V_105 ;
const struct V_12 * V_13 ;
switch ( V_138 -> V_139 ) {
case V_134 :
case V_135 :
if ( V_138 -> V_142 == V_138 -> V_141 )
return 0 ;
V_13 = F_82 ( V_138 -> V_142 , struct V_12 , V_8 ) ;
return ( * V_13 -> V_14 == '\0' ) ? 0 :
F_83 ( V_122 , L_25 , V_13 -> V_14 ) ;
}
return 0 ;
}
static int F_93 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
struct V_121 * V_122 ;
struct V_137 * V_138 ;
int V_5 ;
V_138 = F_63 ( sizeof( * V_138 ) , V_92 ) ;
if ( V_138 == NULL )
return - V_56 ;
V_5 = F_94 ( V_128 , & V_145 ) ;
if ( V_5 < 0 ) {
F_55 ( V_138 ) ;
return V_5 ;
}
V_122 = V_128 -> V_130 ;
V_122 -> V_105 = V_138 ;
V_138 -> V_22 = ( unsigned long ) F_86 ( V_127 ) -> V_76 ;
return 0 ;
}
static void * F_95 ( struct V_121 * V_122 , T_7 * V_123 )
{
return F_88 ( V_122 , V_123 , true ) ;
}
static void * F_96 ( struct V_121 * V_122 , void * V_126 , T_7 * V_131 )
{
return F_87 ( V_122 , V_126 , V_131 , true ) ;
}
static int F_97 ( struct V_121 * V_122 , void * V_126 )
{
const struct V_137 * V_138 = V_122 -> V_105 ;
const struct V_1 * V_2 ;
switch ( V_138 -> V_139 ) {
case V_134 :
case V_135 :
if ( V_138 -> V_142 == V_138 -> V_141 )
return 0 ;
V_2 = F_82 ( V_138 -> V_142 , struct V_1 , V_8 ) ;
return ( * V_2 -> V_14 == '\0' ) ? 0 :
F_83 ( V_122 , L_25 , V_2 -> V_14 ) ;
}
return 0 ;
}
static int F_98 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
struct V_121 * V_122 ;
struct V_137 * V_138 ;
int V_5 ;
V_138 = F_63 ( sizeof( * V_138 ) , V_92 ) ;
if ( V_138 == NULL )
return - V_56 ;
V_5 = F_94 ( V_128 , & V_146 ) ;
if ( V_5 < 0 ) {
F_55 ( V_138 ) ;
return V_5 ;
}
V_122 = V_128 -> V_130 ;
V_122 -> V_105 = V_138 ;
V_138 -> V_22 = ( unsigned long ) F_86 ( V_127 ) -> V_76 ;
return 0 ;
}
struct V_147 * F_99 ( const struct V_100 * V_42 , T_8 * V_148 )
{
unsigned int V_44 = V_42 -> V_149 ;
T_3 V_10 , V_150 = F_100 ( V_44 ) ;
T_3 V_151 ;
struct V_147 * V_152 ;
int V_5 ;
V_152 = F_63 ( sizeof( * V_152 ) * V_150 , V_92 ) ;
if ( V_152 == NULL )
return F_15 ( - V_56 ) ;
for ( V_10 = 0 , V_151 = 0 ; V_10 < V_150 && V_44 != 0 ;
V_44 >>= 1 , ++ V_151 ) {
if ( ! ( V_44 & 1 ) )
continue;
V_152 [ V_10 ] . V_153 = V_148 ;
V_152 [ V_10 ] . V_154 = V_42 -> V_19 ;
V_152 [ V_10 ] . V_155 = V_42 -> V_3 ;
V_152 [ V_10 ] . V_151 = V_151 ;
V_152 [ V_10 ] . V_156 = V_42 -> V_156 ;
++ V_10 ;
}
V_5 = F_101 ( V_152 , V_150 ) ;
if ( V_5 < 0 ) {
F_55 ( V_152 ) ;
return F_15 ( V_5 ) ;
}
return V_152 ;
}
void F_102 ( const struct V_100 * V_42 , struct V_147 * V_152 )
{
F_103 ( V_152 , F_100 ( V_42 -> V_149 ) ) ;
F_55 ( V_152 ) ;
}
int F_104 ( struct V_101 * V_101 , T_1 V_3 )
{
#ifdef F_105
char V_29 [ V_157 ] ;
struct V_158 * V_159 ;
#endif
if ( V_3 >= F_27 ( V_23 ) )
return - V_41 ;
#ifdef F_105
F_106 ( V_29 , V_23 [ V_3 ] , sizeof( V_29 ) ) ;
F_107 ( V_29 , V_160 , sizeof( V_29 ) ) ;
V_159 = F_108 ( V_29 , 0440 , V_101 -> V_161 , & V_162 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_159 )
goto V_116;
F_106 ( V_29 , V_23 [ V_3 ] , sizeof( V_29 ) ) ;
F_107 ( V_29 , V_163 , sizeof( V_29 ) ) ;
V_159 = F_108 ( V_29 , 0440 , V_101 -> V_161 , & V_164 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_159 )
goto V_165;
F_106 ( V_29 , V_23 [ V_3 ] , sizeof( V_29 ) ) ;
F_107 ( V_29 , V_166 , sizeof( V_29 ) ) ;
V_159 = F_108 ( V_29 , 0440 , V_101 -> V_161 , & V_167 ,
( void * ) ( unsigned long ) V_3 ) ;
if ( ! V_159 )
goto V_168;
#endif
return 0 ;
#ifdef F_105
V_168:
F_106 ( V_29 , V_23 [ V_3 ] , sizeof( V_29 ) ) ;
F_107 ( V_29 , V_163 , sizeof( V_29 ) ) ;
F_109 ( V_101 , V_29 ) ;
V_165:
F_106 ( V_29 , V_23 [ V_3 ] , sizeof( V_29 ) ) ;
F_107 ( V_29 , V_160 , sizeof( V_29 ) ) ;
F_109 ( V_101 , V_29 ) ;
V_116:
return - 1 ;
#endif
}
void F_110 ( struct V_101 * V_101 , T_1 V_3 )
{
#ifdef F_105
char V_29 [ V_157 ] ;
F_106 ( V_29 , V_23 [ V_3 ] , sizeof( V_29 ) ) ;
F_107 ( V_29 , V_160 , sizeof( V_29 ) ) ;
F_109 ( V_101 , V_29 ) ;
F_106 ( V_29 , V_23 [ V_3 ] , sizeof( V_29 ) ) ;
F_107 ( V_29 , V_166 , sizeof( V_29 ) ) ;
F_109 ( V_101 , V_29 ) ;
F_106 ( V_29 , V_23 [ V_3 ] , sizeof( V_29 ) ) ;
F_107 ( V_29 , V_163 , sizeof( V_29 ) ) ;
F_109 ( V_101 , V_29 ) ;
#endif
}
static int T_9 F_111 ( struct V_101 * V_101 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_169 ; V_10 ++ )
F_112 ( & V_101 -> V_6 . V_120 [ V_10 ] ) ;
return 0 ;
}
static int T_10 F_113 ( void )
{
unsigned int V_10 ;
int V_170 ;
F_50 (i) {
F_114 ( & F_115 ( V_171 , V_10 ) ) ;
}
V_6 = F_63 ( sizeof( struct V_51 ) * V_169 , V_92 ) ;
if ( ! V_6 )
return - V_56 ;
for ( V_10 = 0 ; V_10 < V_169 ; V_10 ++ ) {
F_116 ( & V_6 [ V_10 ] . V_7 ) ;
#ifdef F_117
F_116 ( & V_6 [ V_10 ] . V_102 ) ;
V_6 [ V_10 ] . V_53 = NULL ;
#endif
F_112 ( & V_6 [ V_10 ] . V_2 ) ;
F_112 ( & V_6 [ V_10 ] . V_13 ) ;
}
V_170 = F_118 ( & V_172 ) ;
if ( V_170 < 0 )
F_55 ( V_6 ) ;
return V_170 ;
}
static void T_11 F_119 ( void )
{
F_120 ( & V_172 ) ;
F_55 ( V_6 ) ;
}
