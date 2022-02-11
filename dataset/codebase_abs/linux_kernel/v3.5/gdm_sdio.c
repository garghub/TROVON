static void F_1 ( char * V_1 , T_1 * V_2 , int V_3 )
{
int V_4 ;
F_2 ( V_5 L_1 , V_1 , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
F_2 ( V_5 L_2 , V_2 [ V_4 ] ) ;
if ( ( V_4 & 0xf ) == 0xf )
F_2 ( V_5 L_3 ) ;
}
F_2 ( V_5 L_3 ) ;
}
static struct V_6 * F_3 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = NULL ;
V_9 = F_4 ( sizeof( * V_9 ) , V_10 ) ;
if ( V_9 == NULL )
goto V_11;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_12 = F_4 ( V_13 , V_10 ) ;
if ( V_9 -> V_12 == NULL )
goto V_11;
V_9 -> V_7 = V_8 ;
return V_9 ;
V_11:
if ( V_9 ) {
F_5 ( V_9 -> V_12 ) ;
F_5 ( V_9 ) ;
}
return NULL ;
}
static void F_6 ( struct V_6 * V_9 )
{
if ( V_9 ) {
F_5 ( V_9 -> V_12 ) ;
F_5 ( V_9 ) ;
}
}
static struct V_14 * F_7 ( struct V_15 * V_16 )
{
struct V_14 * V_17 = NULL ;
V_17 = F_4 ( sizeof( * V_17 ) , V_10 ) ;
if ( V_17 == NULL )
goto V_11;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
V_17 -> V_15 = V_16 ;
return V_17 ;
V_11:
F_5 ( V_17 ) ;
return NULL ;
}
static void F_8 ( struct V_14 * V_17 )
{
F_5 ( V_17 ) ;
}
static struct V_6 * F_9 ( struct V_7 * V_8 , int * V_18 )
{
struct V_6 * V_9 ;
if ( F_10 ( & V_8 -> V_19 ) )
return NULL ;
V_9 = F_11 ( V_8 -> V_19 . V_20 , struct V_6 , V_21 ) ;
F_12 ( & V_9 -> V_21 ) ;
* V_18 = F_10 ( & V_8 -> V_19 ) ? 1 : 0 ;
return V_9 ;
}
static void F_13 ( struct V_7 * V_8 , struct V_6 * V_9 )
{
F_14 ( & V_9 -> V_21 , & V_8 -> V_19 ) ;
}
static struct V_14 * F_15 ( struct V_15 * V_16 )
{
struct V_14 * V_17 ;
if ( F_10 ( & V_16 -> V_19 ) )
return NULL ;
V_17 = F_11 ( V_16 -> V_19 . V_20 , struct V_14 , V_21 ) ;
F_12 ( & V_17 -> V_21 ) ;
return V_17 ;
}
static void F_16 ( struct V_15 * V_16 , struct V_14 * V_17 )
{
F_14 ( & V_17 -> V_21 , & V_16 -> V_19 ) ;
}
static int F_17 ( struct V_22 * V_23 )
{
int V_24 = 0 , V_4 ;
struct V_7 * V_8 = & V_23 -> V_8 ;
struct V_15 * V_16 = & V_23 -> V_16 ;
struct V_6 * V_9 ;
struct V_14 * V_17 ;
F_18 ( & V_8 -> V_19 ) ;
F_18 ( & V_8 -> V_25 ) ;
F_18 ( & V_8 -> V_26 ) ;
F_19 ( & V_8 -> V_27 ) ;
V_8 -> V_28 = F_4 ( V_29 , V_30 ) ;
if ( V_8 -> V_28 == NULL ) {
F_2 ( V_31 L_4 ) ;
goto V_32;
}
for ( V_4 = 0 ; V_4 < V_33 ; V_4 ++ ) {
V_9 = F_3 ( V_8 ) ;
if ( V_9 == NULL ) {
V_24 = - V_34 ;
goto V_32;
}
F_20 ( & V_9 -> V_21 , & V_8 -> V_19 ) ;
}
F_18 ( & V_16 -> V_19 ) ;
F_18 ( & V_16 -> V_35 ) ;
F_19 ( & V_16 -> V_27 ) ;
for ( V_4 = 0 ; V_4 < V_36 ; V_4 ++ ) {
V_17 = F_7 ( V_16 ) ;
if ( V_17 == NULL ) {
V_24 = - V_34 ;
goto V_32;
}
F_20 ( & V_17 -> V_21 , & V_16 -> V_19 ) ;
}
V_16 -> V_37 = F_4 ( V_38 , V_30 ) ;
if ( V_16 -> V_37 == NULL ) {
F_2 ( V_31 L_5 ) ;
goto V_32;
}
return 0 ;
V_32:
F_21 ( V_23 ) ;
return V_24 ;
}
static void F_21 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = & V_23 -> V_8 ;
struct V_15 * V_16 = & V_23 -> V_16 ;
struct V_6 * V_9 , * V_39 ;
struct V_14 * V_17 , * V_40 ;
F_5 ( V_8 -> V_28 ) ;
F_22 (t, t_next, &tx->free_list, list) {
F_12 ( & V_9 -> V_21 ) ;
F_6 ( V_9 ) ;
}
F_22 (t, t_next, &tx->sdu_list, list) {
F_12 ( & V_9 -> V_21 ) ;
F_6 ( V_9 ) ;
}
F_22 (t, t_next, &tx->hci_list, list) {
F_12 ( & V_9 -> V_21 ) ;
F_6 ( V_9 ) ;
}
F_5 ( V_16 -> V_37 ) ;
F_22 (r, r_next, &rx->free_list, list) {
F_12 ( & V_17 -> V_21 ) ;
F_8 ( V_17 ) ;
}
F_22 (r, r_next, &rx->req_list, list) {
F_12 ( & V_17 -> V_21 ) ;
F_8 ( V_17 ) ;
}
}
static void F_23 ( struct V_41 * V_42 , T_1 * V_2 , int V_3 )
{
int V_43 , V_44 , V_24 , V_45 ;
F_24 ( V_42 ) ;
V_44 = V_3 / V_42 -> V_46 ;
V_43 = V_44 * V_42 -> V_46 ;
if ( V_44 ) {
V_24 = F_25 ( V_42 , 0 , V_2 , V_43 ) ;
if ( V_24 < 0 ) {
if ( V_24 != - V_47 )
F_2 ( V_31 L_6 ,
V_48 , V_24 ) ;
goto V_49;
}
}
V_45 = V_3 - V_43 ;
V_45 = ( V_45 + 3 ) & ~ 3 ;
if ( V_45 ) {
V_24 = F_25 ( V_42 , 0 , V_2 + V_43 , V_45 ) ;
if ( V_24 < 0 ) {
if ( V_24 != - V_47 )
F_2 ( V_31 L_6 ,
V_48 , V_24 ) ;
goto V_49;
}
}
V_49:
F_26 ( V_42 ) ;
}
static void F_27 ( struct V_41 * V_42 , struct V_7 * V_8 )
{
struct V_50 * V_51 , * V_52 ;
struct V_53 * V_54 ;
struct V_6 * V_9 ;
int V_55 , V_3 , V_4 , V_56 , V_57 = 0 , V_58 ;
T_1 * V_12 ;
unsigned long V_59 ;
F_28 ( & V_8 -> V_27 , V_59 ) ;
V_55 = V_60 + V_61 ;
F_29 (t, &tx->sdu_list, list) {
V_56 = ( ( V_9 -> V_3 + 3 ) & ~ 3 ) + 4 ;
if ( ( V_55 + V_56 ) > V_29 )
break;
V_57 ++ ;
memcpy ( V_8 -> V_28 + V_55 , V_9 -> V_12 , V_9 -> V_3 ) ;
memset ( V_8 -> V_28 + V_55 + V_9 -> V_3 , 0 , V_56 - V_9 -> V_3 ) ;
V_55 += V_56 ;
}
V_58 = V_55 ;
V_54 = (struct V_53 * ) ( V_8 -> V_28 + V_60 ) ;
V_54 -> V_62 = F_30 ( V_63 ) ;
V_54 -> V_64 = F_30 ( V_58 - V_60 - V_61 ) ;
F_31 ( & V_8 -> V_27 , V_59 ) ;
#ifdef F_32
F_1 ( L_7 , V_8 -> V_28 + V_60 ,
V_58 - V_60 ) ;
#endif
for ( V_55 = V_60 ; V_55 < V_58 ; V_55 += V_65 ) {
V_3 = V_58 - V_55 ;
V_3 = V_3 > V_65 ? V_65 : V_3 ;
V_12 = V_8 -> V_28 + V_55 - V_60 ;
V_12 [ 0 ] = V_3 & 0xff ;
V_12 [ 1 ] = ( V_3 >> 8 ) & 0xff ;
V_12 [ 2 ] = ( V_3 >> 16 ) & 0xff ;
V_12 [ 3 ] = ( V_55 + V_3 ) >= V_58 ? 0 : 1 ;
F_23 ( V_42 , V_12 , V_3 + V_60 ) ;
}
F_28 ( & V_8 -> V_27 , V_59 ) ;
for ( V_51 = V_8 -> V_25 . V_52 , V_4 = 0 ; V_4 < V_57 ; V_4 ++ , V_51 = V_52 ) {
V_52 = V_51 -> V_52 ;
V_9 = F_11 ( V_51 , struct V_6 , V_21 ) ;
if ( V_9 -> V_66 )
V_9 -> V_66 ( V_9 -> V_67 ) ;
F_12 ( V_51 ) ;
F_13 ( V_9 -> V_7 , V_9 ) ;
}
F_33 ( & V_8 -> V_68 ) ;
F_31 ( & V_8 -> V_27 , V_59 ) ;
}
static void F_34 ( struct V_41 * V_42 , struct V_7 * V_8 ,
struct V_6 * V_9 )
{
unsigned long V_59 ;
#ifdef F_32
F_1 ( L_7 , V_9 -> V_12 + V_60 ,
V_9 -> V_3 - V_60 ) ;
#endif
F_23 ( V_42 , V_9 -> V_12 , V_9 -> V_3 ) ;
F_28 ( & V_8 -> V_27 , V_59 ) ;
if ( V_9 -> V_66 )
V_9 -> V_66 ( V_9 -> V_67 ) ;
F_6 ( V_9 ) ;
F_31 ( & V_8 -> V_27 , V_59 ) ;
}
static void F_35 ( struct V_69 * V_70 )
{
struct V_22 * V_23 = F_36 ( V_70 , struct V_22 , V_71 ) ;
struct V_41 * V_42 = V_23 -> V_42 ;
struct V_7 * V_8 = & V_23 -> V_8 ;
struct V_6 * V_9 = NULL ;
struct V_72 V_73 , * V_74 ;
int V_75 = 0 ;
long V_76 ;
unsigned long V_59 ;
F_28 ( & V_8 -> V_27 , V_59 ) ;
if ( ! V_8 -> V_77 ) {
F_31 ( & V_8 -> V_27 , V_59 ) ;
return;
}
if ( ! F_10 ( & V_8 -> V_26 ) ) {
V_9 = F_11 ( V_8 -> V_26 . V_52 , struct V_6 , V_21 ) ;
F_12 ( & V_9 -> V_21 ) ;
V_75 = 0 ;
} else if ( ! V_8 -> V_78 && ! F_10 ( & V_8 -> V_25 ) ) {
F_33 ( & V_73 ) ;
V_74 = & V_8 -> V_68 ;
V_76 = ( V_73 . V_79 - V_74 -> V_79 ) * 1000000 +
( V_73 . V_80 - V_74 -> V_80 ) ;
if ( V_76 >= 0 && V_76 < V_81 ) {
F_37 ( & V_23 -> V_71 ) ;
F_31 ( & V_8 -> V_27 , V_59 ) ;
return;
}
V_75 = 1 ;
}
if ( ! V_75 && V_9 == NULL ) {
F_31 ( & V_8 -> V_27 , V_59 ) ;
return;
}
V_8 -> V_77 = 0 ;
F_31 ( & V_8 -> V_27 , V_59 ) ;
if ( V_75 )
F_27 ( V_42 , V_8 ) ;
else
F_34 ( V_42 , V_8 , V_9 ) ;
}
static int F_38 ( void * V_82 , void * V_2 , int V_3 ,
void (* F_39)( void * V_2 ) , void * V_67 )
{
struct V_22 * V_23 = V_82 ;
struct V_7 * V_8 = & V_23 -> V_8 ;
struct V_6 * V_9 ;
T_1 * V_83 = V_2 ;
int V_18 = 0 ;
T_2 V_62 ;
unsigned long V_59 ;
F_40 ( V_3 > V_13 - V_60 ) ;
F_28 ( & V_8 -> V_27 , V_59 ) ;
V_62 = ( V_83 [ 0 ] << 8 ) | V_83 [ 1 ] ;
if ( V_62 == V_84 ) {
V_9 = F_9 ( V_8 , & V_18 ) ;
if ( V_9 == NULL ) {
F_31 ( & V_8 -> V_27 , V_59 ) ;
return - V_85 ;
}
F_14 ( & V_9 -> V_21 , & V_8 -> V_25 ) ;
memcpy ( V_9 -> V_12 , V_2 , V_3 ) ;
V_9 -> V_3 = V_3 ;
V_9 -> V_66 = F_39 ;
V_9 -> V_67 = V_67 ;
} else {
V_9 = F_3 ( V_8 ) ;
if ( V_9 == NULL ) {
F_31 ( & V_8 -> V_27 , V_59 ) ;
return - V_34 ;
}
F_14 ( & V_9 -> V_21 , & V_8 -> V_26 ) ;
V_9 -> V_12 [ 0 ] = V_3 & 0xff ;
V_9 -> V_12 [ 1 ] = ( V_3 >> 8 ) & 0xff ;
V_9 -> V_12 [ 2 ] = ( V_3 >> 16 ) & 0xff ;
V_9 -> V_12 [ 3 ] = 2 ;
memcpy ( V_9 -> V_12 + V_60 , V_2 , V_3 ) ;
V_9 -> V_3 = V_3 + V_60 ;
V_9 -> V_66 = F_39 ;
V_9 -> V_67 = V_67 ;
}
if ( V_8 -> V_77 )
F_37 ( & V_23 -> V_71 ) ;
F_31 ( & V_8 -> V_27 , V_59 ) ;
if ( V_18 )
return - V_85 ;
return 0 ;
}
static int F_41 ( struct V_22 * V_23 , T_1 * V_86 , int V_3 )
{
struct V_7 * V_8 = & V_23 -> V_8 ;
T_2 V_62 ;
unsigned long V_59 ;
F_28 ( & V_8 -> V_27 , V_59 ) ;
V_62 = ( V_86 [ 0 ] << 8 ) | ( V_86 [ 1 ] ) ;
if ( V_62 != V_87 )
goto V_11;
if ( V_86 [ 4 ] == 0 ) {
#ifdef F_32
F_2 ( V_5 L_8 ) ;
#endif
V_8 -> V_78 = 1 ;
} else if ( V_86 [ 4 ] == 1 ) {
#ifdef F_32
F_2 ( V_5 L_9 ) ;
#endif
V_8 -> V_78 = 0 ;
if ( V_8 -> V_77 )
F_37 ( & V_23 -> V_71 ) ;
if ( F_10 ( & V_8 -> V_19 ) )
V_3 = 0 ;
}
V_11:
F_31 ( & V_8 -> V_27 , V_59 ) ;
return V_3 ;
}
static void F_42 ( struct V_41 * V_42 )
{
struct V_88 * V_88 = F_43 ( V_42 ) ;
struct V_22 * V_23 = V_88 -> V_82 ;
struct V_7 * V_8 = & V_23 -> V_8 ;
struct V_15 * V_16 = & V_23 -> V_16 ;
struct V_14 * V_17 ;
unsigned long V_59 ;
T_1 V_89 , V_90 [ V_91 ] , * V_12 ;
T_3 V_3 , V_44 , V_43 ;
int V_24 , V_45 ;
V_89 = F_44 ( V_42 , 0x13 , & V_24 ) ;
if ( V_89 & 0x01 )
F_45 ( V_42 , 0x01 , 0x13 , & V_24 ) ;
else
return;
V_24 = F_46 ( V_42 , V_90 , 0x0 , V_91 ) ;
if ( V_24 ) {
F_2 ( V_31 L_10 , V_42 -> V_92 ) ;
goto V_93;
}
V_3 = ( V_90 [ 2 ] << 16 ) | ( V_90 [ 1 ] << 8 ) | V_90 [ 0 ] ;
if ( V_3 > ( V_38 - V_60 ) ) {
F_2 ( V_31 L_11 , V_3 ) ;
goto V_93;
}
if ( V_90 [ 3 ] == 1 ) {
#ifdef F_32
T_3 * V_94 = ( T_3 * ) & V_90 [ 4 ] ;
#endif
F_28 ( & V_8 -> V_27 , V_59 ) ;
V_8 -> V_77 = 1 ;
if ( ! F_10 ( & V_8 -> V_25 ) || ! F_10 ( & V_8 -> V_26 ) )
F_37 ( & V_23 -> V_71 ) ;
F_31 ( & V_8 -> V_27 , V_59 ) ;
#ifdef F_32
F_2 ( V_5 L_12 , F_47 ( * V_94 ) ) ;
#endif
goto V_93;
}
memcpy ( V_16 -> V_37 , V_90 + V_60 ,
V_91 - V_60 ) ;
V_12 = V_16 -> V_37 + V_91 - V_60 ;
V_45 = V_3 - V_91 + V_60 ;
if ( V_45 <= 0 )
goto V_49;
V_44 = V_45 / V_42 -> V_46 ;
if ( V_44 ) {
V_43 = V_44 * V_42 -> V_46 ;
V_24 = F_46 ( V_42 , V_12 , 0x0 , V_43 ) ;
if ( V_24 ) {
F_2 ( V_31 L_10 ,
V_42 -> V_92 ) ;
goto V_93;
}
V_12 += V_43 ;
V_45 -= V_43 ;
}
if ( V_45 ) {
V_24 = F_46 ( V_42 , V_12 , 0x0 , V_45 ) ;
if ( V_24 ) {
F_2 ( V_31 L_10 ,
V_42 -> V_92 ) ;
goto V_93;
}
}
V_49:
#ifdef F_32
F_1 ( L_13 , V_16 -> V_37 , V_3 ) ;
#endif
V_3 = F_41 ( V_23 , V_16 -> V_37 , V_3 ) ;
F_28 ( & V_16 -> V_27 , V_59 ) ;
if ( ! F_10 ( & V_16 -> V_35 ) ) {
V_17 = F_11 ( V_16 -> V_35 . V_52 , struct V_14 , V_21 ) ;
F_31 ( & V_16 -> V_27 , V_59 ) ;
if ( V_17 -> V_66 )
V_17 -> V_66 ( V_17 -> V_67 , V_16 -> V_37 , V_3 ) ;
F_28 ( & V_16 -> V_27 , V_59 ) ;
F_12 ( & V_17 -> V_21 ) ;
F_16 ( V_16 , V_17 ) ;
}
F_31 ( & V_16 -> V_27 , V_59 ) ;
V_93:
F_45 ( V_42 , 0x00 , 0x10 , & V_24 ) ;
if ( ! V_88 -> V_95 )
F_48 ( V_88 , & V_42 -> V_96 ) ;
}
static int F_49 ( void * V_82 ,
void (* F_39)( void * V_67 , void * V_2 , int V_3 ) ,
void * V_67 )
{
struct V_22 * V_23 = V_82 ;
struct V_15 * V_16 = & V_23 -> V_16 ;
struct V_14 * V_17 ;
unsigned long V_59 ;
F_28 ( & V_16 -> V_27 , V_59 ) ;
V_17 = F_15 ( V_16 ) ;
if ( V_17 == NULL ) {
F_31 ( & V_16 -> V_27 , V_59 ) ;
return - V_34 ;
}
V_17 -> V_66 = F_39 ;
V_17 -> V_67 = V_67 ;
F_14 ( & V_17 -> V_21 , & V_16 -> V_35 ) ;
F_31 ( & V_16 -> V_27 , V_59 ) ;
return 0 ;
}
static int F_50 ( struct V_41 * V_42 ,
const struct V_97 * V_98 )
{
int V_24 ;
struct V_88 * V_88 = NULL ;
struct V_22 * V_23 = NULL ;
F_2 ( V_99 L_14 ,
V_42 -> V_100 , V_42 -> V_101 ) ;
F_2 ( V_99 L_15 , V_102 ) ;
F_24 ( V_42 ) ;
F_51 ( V_42 ) ;
F_52 ( V_42 , F_42 ) ;
V_24 = F_53 ( V_42 ) ;
if ( V_24 )
return V_24 ;
V_88 = F_4 ( sizeof( * V_88 ) , V_30 ) ;
if ( V_88 == NULL ) {
V_24 = - V_34 ;
goto V_11;
}
V_23 = F_4 ( sizeof( * V_23 ) , V_30 ) ;
if ( V_23 == NULL ) {
V_24 = - V_34 ;
goto V_11;
}
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_88 -> V_82 = ( void * ) V_23 ;
V_88 -> V_103 = F_38 ;
V_88 -> V_104 = F_49 ;
V_24 = F_17 ( V_23 ) ;
if ( V_23 < 0 )
goto V_11;
V_23 -> V_42 = V_42 ;
F_45 ( V_42 , 1 , 0x14 , & V_24 ) ;
F_26 ( V_42 ) ;
F_54 ( & V_23 -> V_71 , F_35 ) ;
F_55 ( V_42 , V_88 ) ;
V_11:
if ( V_24 ) {
F_5 ( V_88 ) ;
F_5 ( V_23 ) ;
}
return V_24 ;
}
static void F_56 ( struct V_41 * V_42 )
{
struct V_88 * V_88 = F_43 ( V_42 ) ;
struct V_22 * V_23 = V_88 -> V_82 ;
if ( V_88 -> V_95 )
F_57 ( V_88 ) ;
F_24 ( V_42 ) ;
F_58 ( V_42 ) ;
F_59 ( V_42 ) ;
F_26 ( V_42 ) ;
F_21 ( V_23 ) ;
F_5 ( V_23 ) ;
F_5 ( V_88 ) ;
}
static int T_4 F_60 ( void )
{
return F_61 ( & V_105 ) ;
}
static void T_5 F_62 ( void )
{
F_63 ( & V_105 ) ;
}
