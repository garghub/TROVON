static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_6 = F_3 ( V_7 , V_5 ) ;
if ( ! V_4 -> V_6 ) {
F_4 ( V_4 ) ;
return NULL ;
}
V_4 -> V_2 = V_3 ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_4 )
{
if ( V_4 ) {
F_4 ( V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
}
}
static struct V_8 * F_6 ( struct V_9 * V_10 )
{
struct V_8 * V_11 = F_2 ( sizeof( * V_11 ) , V_5 ) ;
if ( V_11 )
V_11 -> V_9 = V_10 ;
return V_11 ;
}
static void F_7 ( struct V_8 * V_11 )
{
F_4 ( V_11 ) ;
}
static struct V_1 * F_8 ( struct V_2 * V_3 , int * V_12 )
{
struct V_1 * V_4 ;
if ( F_9 ( & V_3 -> V_13 ) )
return NULL ;
V_4 = F_10 ( V_3 -> V_13 . V_14 , struct V_1 , V_15 ) ;
F_11 ( & V_4 -> V_15 ) ;
* V_12 = F_9 ( & V_3 -> V_13 ) ? 1 : 0 ;
return V_4 ;
}
static void F_12 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
F_13 ( & V_4 -> V_15 , & V_3 -> V_13 ) ;
}
static struct V_8 * F_14 ( struct V_9 * V_10 )
{
struct V_8 * V_11 ;
if ( F_9 ( & V_10 -> V_13 ) )
return NULL ;
V_11 = F_10 ( V_10 -> V_13 . V_14 , struct V_8 , V_15 ) ;
F_11 ( & V_11 -> V_15 ) ;
return V_11 ;
}
static void F_15 ( struct V_9 * V_10 , struct V_8 * V_11 )
{
F_13 ( & V_11 -> V_15 , & V_10 -> V_13 ) ;
}
static int F_16 ( struct V_16 * V_17 )
{
int V_18 = 0 , V_19 ;
struct V_2 * V_3 = & V_17 -> V_3 ;
struct V_9 * V_10 = & V_17 -> V_10 ;
struct V_1 * V_4 ;
struct V_8 * V_11 ;
F_17 ( & V_3 -> V_13 ) ;
F_17 ( & V_3 -> V_20 ) ;
F_17 ( & V_3 -> V_21 ) ;
F_18 ( & V_3 -> V_22 ) ;
V_3 -> V_23 = F_3 ( V_24 , V_25 ) ;
if ( V_3 -> V_23 == NULL )
goto V_26;
for ( V_19 = 0 ; V_19 < V_27 ; V_19 ++ ) {
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL ) {
V_18 = - V_28 ;
goto V_26;
}
F_19 ( & V_4 -> V_15 , & V_3 -> V_13 ) ;
}
F_17 ( & V_10 -> V_13 ) ;
F_17 ( & V_10 -> V_29 ) ;
F_18 ( & V_10 -> V_22 ) ;
for ( V_19 = 0 ; V_19 < V_30 ; V_19 ++ ) {
V_11 = F_6 ( V_10 ) ;
if ( V_11 == NULL ) {
V_18 = - V_28 ;
goto V_26;
}
F_19 ( & V_11 -> V_15 , & V_10 -> V_13 ) ;
}
V_10 -> V_31 = F_3 ( V_32 , V_25 ) ;
if ( V_10 -> V_31 == NULL )
goto V_26;
return 0 ;
V_26:
F_20 ( V_17 ) ;
return V_18 ;
}
static void F_20 ( struct V_16 * V_17 )
{
struct V_2 * V_3 = & V_17 -> V_3 ;
struct V_9 * V_10 = & V_17 -> V_10 ;
struct V_1 * V_4 , * V_33 ;
struct V_8 * V_11 , * V_34 ;
F_4 ( V_3 -> V_23 ) ;
F_21 (t, t_next, &tx->free_list, list) {
F_11 ( & V_4 -> V_15 ) ;
F_5 ( V_4 ) ;
}
F_21 (t, t_next, &tx->sdu_list, list) {
F_11 ( & V_4 -> V_15 ) ;
F_5 ( V_4 ) ;
}
F_21 (t, t_next, &tx->hci_list, list) {
F_11 ( & V_4 -> V_15 ) ;
F_5 ( V_4 ) ;
}
F_4 ( V_10 -> V_31 ) ;
F_21 (r, r_next, &rx->free_list, list) {
F_11 ( & V_11 -> V_15 ) ;
F_7 ( V_11 ) ;
}
F_21 (r, r_next, &rx->req_list, list) {
F_11 ( & V_11 -> V_15 ) ;
F_7 ( V_11 ) ;
}
}
static void F_22 ( struct V_35 * V_36 , T_1 * V_37 , int V_38 )
{
int V_39 , V_40 , V_18 , V_41 ;
F_23 ( V_36 ) ;
V_40 = V_38 / V_36 -> V_42 ;
V_39 = V_40 * V_36 -> V_42 ;
if ( V_40 ) {
V_18 = F_24 ( V_36 , 0 , V_37 , V_39 ) ;
if ( V_18 < 0 ) {
if ( V_18 != - V_43 )
F_25 ( & V_36 -> V_44 ,
L_1 ,
V_45 , V_18 ) ;
goto V_46;
}
}
V_41 = V_38 - V_39 ;
V_41 = ( V_41 + 3 ) & ~ 3 ;
if ( V_41 ) {
V_18 = F_24 ( V_36 , 0 , V_37 + V_39 , V_41 ) ;
if ( V_18 < 0 ) {
if ( V_18 != - V_43 )
F_25 ( & V_36 -> V_44 ,
L_1 ,
V_45 , V_18 ) ;
goto V_46;
}
}
V_46:
F_26 ( V_36 ) ;
}
static void F_27 ( struct V_35 * V_36 , struct V_2 * V_3 )
{
struct V_47 * V_48 , * V_49 ;
struct V_50 * V_51 ;
struct V_1 * V_4 ;
int V_52 , V_38 , V_19 , V_53 , V_54 = 0 , V_55 ;
T_1 * V_6 ;
unsigned long V_56 ;
F_28 ( & V_3 -> V_22 , V_56 ) ;
V_52 = V_57 + V_58 ;
F_29 (t, &tx->sdu_list, list) {
V_53 = ( ( V_4 -> V_38 + 3 ) & ~ 3 ) + 4 ;
if ( ( V_52 + V_53 ) > V_24 )
break;
V_54 ++ ;
memcpy ( V_3 -> V_23 + V_52 , V_4 -> V_6 , V_4 -> V_38 ) ;
memset ( V_3 -> V_23 + V_52 + V_4 -> V_38 , 0 , V_53 - V_4 -> V_38 ) ;
V_52 += V_53 ;
}
V_55 = V_52 ;
V_51 = (struct V_50 * ) ( V_3 -> V_23 + V_57 ) ;
V_51 -> V_59 = F_30 ( V_60 ) ;
V_51 -> V_61 = F_30 ( V_55 - V_57 - V_58 ) ;
F_31 ( & V_3 -> V_22 , V_56 ) ;
F_32 ( L_2 , V_62 , 16 , 1 ,
V_3 -> V_23 + V_57 ,
V_55 - V_57 , false ) ;
for ( V_52 = V_57 ; V_52 < V_55 ; V_52 += V_63 ) {
V_38 = V_55 - V_52 ;
V_38 = V_38 > V_63 ? V_63 : V_38 ;
V_6 = V_3 -> V_23 + V_52 - V_57 ;
V_6 [ 0 ] = V_38 & 0xff ;
V_6 [ 1 ] = ( V_38 >> 8 ) & 0xff ;
V_6 [ 2 ] = ( V_38 >> 16 ) & 0xff ;
V_6 [ 3 ] = ( V_52 + V_38 ) >= V_55 ? 0 : 1 ;
F_22 ( V_36 , V_6 , V_38 + V_57 ) ;
}
F_28 ( & V_3 -> V_22 , V_56 ) ;
for ( V_48 = V_3 -> V_20 . V_49 , V_19 = 0 ; V_19 < V_54 ; V_19 ++ , V_48 = V_49 ) {
V_49 = V_48 -> V_49 ;
V_4 = F_10 ( V_48 , struct V_1 , V_15 ) ;
if ( V_4 -> V_64 )
V_4 -> V_64 ( V_4 -> V_65 ) ;
F_11 ( V_48 ) ;
F_12 ( V_4 -> V_2 , V_4 ) ;
}
F_33 ( & V_3 -> V_66 ) ;
F_31 ( & V_3 -> V_22 , V_56 ) ;
}
static void F_34 ( struct V_35 * V_36 , struct V_2 * V_3 ,
struct V_1 * V_4 )
{
unsigned long V_56 ;
F_32 ( L_2 , V_62 , 16 , 1 ,
V_4 -> V_6 + V_57 ,
V_4 -> V_38 - V_57 , false ) ;
F_22 ( V_36 , V_4 -> V_6 , V_4 -> V_38 ) ;
F_28 ( & V_3 -> V_22 , V_56 ) ;
if ( V_4 -> V_64 )
V_4 -> V_64 ( V_4 -> V_65 ) ;
F_5 ( V_4 ) ;
F_31 ( & V_3 -> V_22 , V_56 ) ;
}
static void F_35 ( struct V_67 * V_68 )
{
struct V_16 * V_17 = F_36 ( V_68 , struct V_16 , V_69 ) ;
struct V_35 * V_36 = V_17 -> V_36 ;
struct V_2 * V_3 = & V_17 -> V_3 ;
struct V_1 * V_4 = NULL ;
struct V_70 V_71 , * V_72 ;
int V_73 = 0 ;
long V_74 ;
unsigned long V_56 ;
F_28 ( & V_3 -> V_22 , V_56 ) ;
if ( ! V_3 -> V_75 ) {
F_31 ( & V_3 -> V_22 , V_56 ) ;
return;
}
if ( ! F_9 ( & V_3 -> V_21 ) ) {
V_4 = F_10 ( V_3 -> V_21 . V_49 , struct V_1 , V_15 ) ;
F_11 ( & V_4 -> V_15 ) ;
V_73 = 0 ;
} else if ( ! V_3 -> V_76 && ! F_9 ( & V_3 -> V_20 ) ) {
F_33 ( & V_71 ) ;
V_72 = & V_3 -> V_66 ;
V_74 = ( V_71 . V_77 - V_72 -> V_77 ) * 1000000 +
( V_71 . V_78 - V_72 -> V_78 ) ;
if ( V_74 >= 0 && V_74 < V_79 ) {
F_37 ( & V_17 -> V_69 ) ;
F_31 ( & V_3 -> V_22 , V_56 ) ;
return;
}
V_73 = 1 ;
}
if ( ! V_73 && V_4 == NULL ) {
F_31 ( & V_3 -> V_22 , V_56 ) ;
return;
}
V_3 -> V_75 = 0 ;
F_31 ( & V_3 -> V_22 , V_56 ) ;
if ( V_73 )
F_27 ( V_36 , V_3 ) ;
else
F_34 ( V_36 , V_3 , V_4 ) ;
}
static int F_38 ( void * V_80 , void * V_37 , int V_38 ,
void (* F_39)( void * V_37 ) , void * V_65 )
{
struct V_16 * V_17 = V_80 ;
struct V_2 * V_3 = & V_17 -> V_3 ;
struct V_1 * V_4 ;
T_1 * V_81 = V_37 ;
int V_12 = 0 ;
T_2 V_59 ;
unsigned long V_56 ;
F_40 ( V_38 > V_7 - V_57 ) ;
F_28 ( & V_3 -> V_22 , V_56 ) ;
V_59 = ( V_81 [ 0 ] << 8 ) | V_81 [ 1 ] ;
if ( V_59 == V_82 ) {
V_4 = F_8 ( V_3 , & V_12 ) ;
if ( V_4 == NULL ) {
F_31 ( & V_3 -> V_22 , V_56 ) ;
return - V_83 ;
}
F_13 ( & V_4 -> V_15 , & V_3 -> V_20 ) ;
memcpy ( V_4 -> V_6 , V_37 , V_38 ) ;
V_4 -> V_38 = V_38 ;
V_4 -> V_64 = F_39 ;
V_4 -> V_65 = V_65 ;
} else {
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL ) {
F_31 ( & V_3 -> V_22 , V_56 ) ;
return - V_28 ;
}
F_13 ( & V_4 -> V_15 , & V_3 -> V_21 ) ;
V_4 -> V_6 [ 0 ] = V_38 & 0xff ;
V_4 -> V_6 [ 1 ] = ( V_38 >> 8 ) & 0xff ;
V_4 -> V_6 [ 2 ] = ( V_38 >> 16 ) & 0xff ;
V_4 -> V_6 [ 3 ] = 2 ;
memcpy ( V_4 -> V_6 + V_57 , V_37 , V_38 ) ;
V_4 -> V_38 = V_38 + V_57 ;
V_4 -> V_64 = F_39 ;
V_4 -> V_65 = V_65 ;
}
if ( V_3 -> V_75 )
F_37 ( & V_17 -> V_69 ) ;
F_31 ( & V_3 -> V_22 , V_56 ) ;
if ( V_12 )
return - V_83 ;
return 0 ;
}
static int F_41 ( struct V_16 * V_17 , T_1 * V_84 , int V_38 )
{
struct V_2 * V_3 = & V_17 -> V_3 ;
T_2 V_59 ;
unsigned long V_56 ;
F_28 ( & V_3 -> V_22 , V_56 ) ;
V_59 = ( V_84 [ 0 ] << 8 ) | ( V_84 [ 1 ] ) ;
if ( V_59 != V_85 )
goto V_86;
if ( V_84 [ 4 ] == 0 ) {
F_42 ( & V_17 -> V_36 -> V_44 , L_3 ) ;
V_3 -> V_76 = 1 ;
} else if ( V_84 [ 4 ] == 1 ) {
F_42 ( & V_17 -> V_36 -> V_44 , L_4 ) ;
V_3 -> V_76 = 0 ;
if ( V_3 -> V_75 )
F_37 ( & V_17 -> V_69 ) ;
if ( F_9 ( & V_3 -> V_13 ) )
V_38 = 0 ;
}
V_86:
F_31 ( & V_3 -> V_22 , V_56 ) ;
return V_38 ;
}
static void F_43 ( struct V_35 * V_36 )
{
struct V_87 * V_87 = F_44 ( V_36 ) ;
struct V_16 * V_17 = V_87 -> V_80 ;
struct V_2 * V_3 = & V_17 -> V_3 ;
struct V_9 * V_10 = & V_17 -> V_10 ;
struct V_8 * V_11 ;
unsigned long V_56 ;
T_1 V_88 , V_89 [ V_90 ] , * V_6 ;
T_3 V_38 , V_40 , V_39 ;
int V_18 , V_41 ;
V_88 = F_45 ( V_36 , 0x13 , & V_18 ) ;
if ( V_88 & 0x01 )
F_46 ( V_36 , 0x01 , 0x13 , & V_18 ) ;
else
return;
V_18 = F_47 ( V_36 , V_89 , 0x0 , V_90 ) ;
if ( V_18 ) {
F_25 ( & V_36 -> V_44 ,
L_5 , V_36 -> V_91 ) ;
goto V_92;
}
V_38 = ( V_89 [ 2 ] << 16 ) | ( V_89 [ 1 ] << 8 ) | V_89 [ 0 ] ;
if ( V_38 > ( V_32 - V_57 ) ) {
F_25 ( & V_36 -> V_44 , L_6 , V_38 ) ;
goto V_92;
}
if ( V_89 [ 3 ] == 1 ) {
T_3 * V_93 = ( T_3 * ) & V_89 [ 4 ] ;
F_28 ( & V_3 -> V_22 , V_56 ) ;
V_3 -> V_75 = 1 ;
if ( ! F_9 ( & V_3 -> V_20 ) || ! F_9 ( & V_3 -> V_21 ) )
F_37 ( & V_17 -> V_69 ) ;
F_31 ( & V_3 -> V_22 , V_56 ) ;
F_42 ( & V_36 -> V_44 , L_7 , F_48 ( * V_93 ) ) ;
goto V_92;
}
memcpy ( V_10 -> V_31 , V_89 + V_57 ,
V_90 - V_57 ) ;
V_6 = V_10 -> V_31 + V_90 - V_57 ;
V_41 = V_38 - V_90 + V_57 ;
if ( V_41 <= 0 )
goto V_46;
V_40 = V_41 / V_36 -> V_42 ;
if ( V_40 ) {
V_39 = V_40 * V_36 -> V_42 ;
V_18 = F_47 ( V_36 , V_6 , 0x0 , V_39 ) ;
if ( V_18 ) {
F_25 ( & V_36 -> V_44 ,
L_5 , V_36 -> V_91 ) ;
goto V_92;
}
V_6 += V_39 ;
V_41 -= V_39 ;
}
if ( V_41 ) {
V_18 = F_47 ( V_36 , V_6 , 0x0 , V_41 ) ;
if ( V_18 ) {
F_25 ( & V_36 -> V_44 ,
L_5 , V_36 -> V_91 ) ;
goto V_92;
}
}
V_46:
F_32 ( L_8 , V_62 , 16 , 1 ,
V_10 -> V_31 , V_38 , false ) ;
V_38 = F_41 ( V_17 , V_10 -> V_31 , V_38 ) ;
F_28 ( & V_10 -> V_22 , V_56 ) ;
if ( ! F_9 ( & V_10 -> V_29 ) ) {
V_11 = F_10 ( V_10 -> V_29 . V_49 , struct V_8 , V_15 ) ;
F_31 ( & V_10 -> V_22 , V_56 ) ;
if ( V_11 -> V_64 )
V_11 -> V_64 ( V_11 -> V_65 , V_10 -> V_31 , V_38 ) ;
F_28 ( & V_10 -> V_22 , V_56 ) ;
F_11 ( & V_11 -> V_15 ) ;
F_15 ( V_10 , V_11 ) ;
}
F_31 ( & V_10 -> V_22 , V_56 ) ;
V_92:
F_46 ( V_36 , 0x00 , 0x10 , & V_18 ) ;
if ( ! V_87 -> V_94 )
F_49 ( V_87 , & V_36 -> V_44 ) ;
}
static int F_50 ( void * V_80 ,
void (* F_39)( void * V_65 , void * V_37 , int V_38 ) ,
void * V_65 )
{
struct V_16 * V_17 = V_80 ;
struct V_9 * V_10 = & V_17 -> V_10 ;
struct V_8 * V_11 ;
unsigned long V_56 ;
F_28 ( & V_10 -> V_22 , V_56 ) ;
V_11 = F_14 ( V_10 ) ;
if ( V_11 == NULL ) {
F_31 ( & V_10 -> V_22 , V_56 ) ;
return - V_28 ;
}
V_11 -> V_64 = F_39 ;
V_11 -> V_65 = V_65 ;
F_13 ( & V_11 -> V_15 , & V_10 -> V_29 ) ;
F_31 ( & V_10 -> V_22 , V_56 ) ;
return 0 ;
}
static int F_51 ( struct V_35 * V_36 ,
const struct V_95 * V_96 )
{
int V_18 ;
struct V_87 * V_87 = NULL ;
struct V_16 * V_17 = NULL ;
F_52 ( & V_36 -> V_44 , L_9 ,
V_36 -> V_97 , V_36 -> V_98 ) ;
F_52 ( & V_36 -> V_44 , L_10 , V_99 ) ;
F_23 ( V_36 ) ;
F_53 ( V_36 ) ;
F_54 ( V_36 , F_43 ) ;
V_18 = F_55 ( V_36 ) ;
if ( V_18 )
return V_18 ;
V_87 = F_2 ( sizeof( * V_87 ) , V_25 ) ;
if ( V_87 == NULL ) {
V_18 = - V_28 ;
goto V_86;
}
V_17 = F_2 ( sizeof( * V_17 ) , V_25 ) ;
if ( V_17 == NULL ) {
V_18 = - V_28 ;
goto V_86;
}
V_87 -> V_80 = ( void * ) V_17 ;
V_87 -> V_100 = F_38 ;
V_87 -> V_101 = F_50 ;
V_18 = F_16 ( V_17 ) ;
if ( V_18 < 0 )
goto V_86;
V_17 -> V_36 = V_36 ;
F_46 ( V_36 , 1 , 0x14 , & V_18 ) ;
F_26 ( V_36 ) ;
F_56 ( & V_17 -> V_69 , F_35 ) ;
F_57 ( V_36 , V_87 ) ;
V_86:
if ( V_18 ) {
F_4 ( V_87 ) ;
F_4 ( V_17 ) ;
}
return V_18 ;
}
static void F_58 ( struct V_35 * V_36 )
{
struct V_87 * V_87 = F_44 ( V_36 ) ;
struct V_16 * V_17 = V_87 -> V_80 ;
F_59 ( & V_17 -> V_69 ) ;
if ( V_87 -> V_94 )
F_60 ( V_87 ) ;
F_23 ( V_36 ) ;
F_61 ( V_36 ) ;
F_62 ( V_36 ) ;
F_26 ( V_36 ) ;
F_20 ( V_17 ) ;
F_4 ( V_17 ) ;
F_4 ( V_87 ) ;
}
static int T_4 F_63 ( void )
{
return F_64 ( & V_102 ) ;
}
static void T_5 F_65 ( void )
{
F_66 ( & V_102 ) ;
}
