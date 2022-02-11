static bool F_1 ( T_1 V_1 , T_1 V_2 )
{
if ( ( int ) V_2 - V_1 == 32768 )
return false ;
return ( ( ( V_3 ) ( V_2 - V_1 ) ) < 0 ) ;
}
bool F_2 ( struct V_4 * V_5 , unsigned char * V_6 )
{
struct V_7 * V_8 ;
V_8 = F_3 ( & V_5 -> V_9 , struct V_7 ,
V_10 ) ;
if ( ! V_8 ) {
F_4 ( 1 , L_1 ) ;
return false ;
}
if ( F_5 ( V_6 , V_8 -> V_11 ) )
return true ;
if ( F_5 ( V_6 , V_8 -> V_12 ) )
return true ;
return false ;
}
static struct V_7 * F_6 ( struct V_13 * V_14 ,
const unsigned char V_6 [ V_15 ] )
{
struct V_7 * V_8 ;
F_7 (node, node_db, mac_list) {
if ( F_5 ( V_8 -> V_11 , V_6 ) )
return V_8 ;
}
return NULL ;
}
int F_8 ( struct V_13 * V_9 ,
unsigned char V_16 [ V_15 ] ,
unsigned char V_17 [ V_15 ] )
{
struct V_7 * V_8 , * V_18 ;
V_8 = F_9 ( sizeof( * V_8 ) , V_19 ) ;
if ( ! V_8 )
return - V_20 ;
F_10 ( V_8 -> V_11 , V_16 ) ;
F_10 ( V_8 -> V_12 , V_17 ) ;
F_11 () ;
V_18 = F_3 ( V_9 ,
struct V_7 , V_10 ) ;
if ( V_18 ) {
F_12 ( & V_18 -> V_10 , & V_8 -> V_10 ) ;
F_13 () ;
F_14 () ;
F_15 ( V_18 ) ;
} else {
F_13 () ;
F_16 ( & V_8 -> V_10 , V_9 ) ;
}
return 0 ;
}
struct V_7 * F_17 ( struct V_13 * V_14 , unsigned char V_6 [] ,
T_1 V_21 )
{
struct V_7 * V_8 ;
unsigned long V_22 ;
int V_23 ;
V_8 = F_18 ( sizeof( * V_8 ) , V_24 ) ;
if ( ! V_8 )
return NULL ;
F_10 ( V_8 -> V_11 , V_6 ) ;
V_22 = V_25 ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ )
V_8 -> V_27 [ V_23 ] = V_22 ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ )
V_8 -> V_21 [ V_23 ] = V_21 ;
F_16 ( & V_8 -> V_10 , V_14 ) ;
return V_8 ;
}
struct V_7 * F_19 ( struct V_28 * V_29 , struct V_30 * V_31 ,
bool V_32 )
{
struct V_13 * V_14 = & V_29 -> V_5 -> V_14 ;
struct V_7 * V_8 ;
struct V_33 * V_33 ;
T_1 V_21 ;
if ( ! F_20 ( V_31 ) )
return NULL ;
V_33 = (struct V_33 * ) F_21 ( V_31 ) ;
F_7 (node, node_db, mac_list) {
if ( F_5 ( V_8 -> V_11 , V_33 -> V_34 ) )
return V_8 ;
if ( F_5 ( V_8 -> V_12 , V_33 -> V_34 ) )
return V_8 ;
}
if ( V_33 -> V_35 == F_22 ( V_36 )
|| V_33 -> V_35 == F_22 ( V_37 ) ) {
V_21 = F_23 ( V_31 ) - 1 ;
} else {
if ( V_29 -> type != V_38 )
F_4 ( 1 , L_2 , V_39 ) ;
V_21 = V_40 ;
}
return F_17 ( V_14 , V_33 -> V_34 , V_21 ) ;
}
void F_24 ( struct V_30 * V_31 , struct V_7 * V_41 ,
struct V_28 * V_42 )
{
struct V_33 * V_33 ;
struct V_7 * V_43 ;
struct V_44 * V_45 ;
struct V_13 * V_14 ;
int V_23 ;
V_33 = (struct V_33 * ) F_21 ( V_31 ) ;
F_25 ( V_31 , sizeof( struct V_33 ) ) ;
if ( V_33 -> V_35 == F_22 ( V_37 ) )
F_25 ( V_31 , sizeof( struct V_46 ) ) ;
F_25 ( V_31 , sizeof( struct V_47 ) ) ;
V_45 = (struct V_44 * ) V_31 -> V_48 ;
V_14 = & V_42 -> V_5 -> V_14 ;
V_43 = F_6 ( V_14 , V_45 -> V_11 ) ;
if ( ! V_43 )
V_43 = F_17 ( V_14 , V_45 -> V_11 ,
V_40 - 1 ) ;
if ( ! V_43 )
goto V_49;
if ( V_43 == V_41 )
goto V_49;
F_10 ( V_43 -> V_12 , V_33 -> V_34 ) ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
if ( ! V_41 -> V_50 [ V_23 ] &&
F_26 ( V_41 -> V_27 [ V_23 ] , V_43 -> V_27 [ V_23 ] ) ) {
V_43 -> V_27 [ V_23 ] = V_41 -> V_27 [ V_23 ] ;
V_43 -> V_50 [ V_23 ] = V_41 -> V_50 [ V_23 ] ;
}
if ( F_1 ( V_41 -> V_21 [ V_23 ] , V_43 -> V_21 [ V_23 ] ) )
V_43 -> V_21 [ V_23 ] = V_41 -> V_21 [ V_23 ] ;
}
V_43 -> V_51 = V_42 -> type ;
F_27 ( & V_41 -> V_10 ) ;
F_28 ( V_41 , V_52 ) ;
V_49:
F_29 ( V_31 , sizeof( struct V_53 ) ) ;
}
void F_30 ( struct V_7 * V_8 , struct V_30 * V_31 )
{
if ( ! F_20 ( V_31 ) ) {
F_4 ( 1 , L_3 , V_39 ) ;
return;
}
memcpy ( & F_31 ( V_31 ) -> V_34 , V_8 -> V_11 , V_15 ) ;
}
void F_32 ( struct V_7 * V_54 , struct V_30 * V_31 ,
struct V_28 * V_29 )
{
struct V_7 * V_55 ;
if ( ! F_20 ( V_31 ) ) {
F_4 ( 1 , L_3 , V_39 ) ;
return;
}
if ( ! F_33 ( F_31 ( V_31 ) -> V_56 ) )
return;
V_55 = F_6 ( & V_29 -> V_5 -> V_14 , F_31 ( V_31 ) -> V_56 ) ;
if ( ! V_55 ) {
F_4 ( 1 , L_4 , V_39 ) ;
return;
}
if ( V_29 -> type != V_55 -> V_51 )
return;
F_10 ( F_31 ( V_31 ) -> V_56 , V_55 -> V_12 ) ;
}
void F_34 ( struct V_7 * V_8 , struct V_28 * V_29 ,
T_1 V_57 )
{
if ( F_35 ( V_57 , V_8 -> V_21 [ V_29 -> type ] ) )
return;
V_8 -> V_27 [ V_29 -> type ] = V_25 ;
V_8 -> V_50 [ V_29 -> type ] = false ;
}
int F_36 ( struct V_28 * V_29 , struct V_7 * V_8 ,
T_1 V_57 )
{
if ( F_37 ( V_57 , V_8 -> V_21 [ V_29 -> type ] ) )
return 1 ;
V_8 -> V_21 [ V_29 -> type ] = V_57 ;
return 0 ;
}
static struct V_28 * F_38 ( struct V_4 * V_5 ,
struct V_7 * V_8 )
{
if ( V_8 -> V_50 [ V_58 ] )
return F_39 ( V_5 , V_58 ) ;
if ( V_8 -> V_50 [ V_59 ] )
return F_39 ( V_5 , V_59 ) ;
if ( F_26 ( V_8 -> V_27 [ V_59 ] ,
V_8 -> V_27 [ V_58 ] +
F_40 ( V_60 ) ) )
return F_39 ( V_5 , V_58 ) ;
if ( F_26 ( V_8 -> V_27 [ V_58 ] ,
V_8 -> V_27 [ V_59 ] +
F_40 ( V_60 ) ) )
return F_39 ( V_5 , V_59 ) ;
return NULL ;
}
void F_41 ( unsigned long V_48 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
struct V_28 * V_29 ;
unsigned long V_61 ;
unsigned long V_62 , V_63 ;
V_5 = (struct V_4 * ) V_48 ;
F_11 () ;
F_7 (node, &hsr->node_db, mac_list) {
V_62 = V_8 -> V_27 [ V_58 ] ;
V_63 = V_8 -> V_27 [ V_59 ] ;
if ( F_26 ( V_25 , V_62 + V_64 / 2 ) )
V_8 -> V_50 [ V_58 ] = true ;
if ( F_26 ( V_25 , V_63 + V_64 / 2 ) )
V_8 -> V_50 [ V_59 ] = true ;
V_61 = V_62 ;
if ( V_8 -> V_50 [ V_58 ] ||
( ! V_8 -> V_50 [ V_59 ] &&
F_26 ( V_63 , V_62 ) ) )
V_61 = V_63 ;
if ( F_42 ( V_61 +
F_40 ( 1.5 * V_60 ) ) ) {
F_11 () ;
V_29 = F_38 ( V_5 , V_8 ) ;
if ( V_29 != NULL )
F_43 ( V_5 , V_8 -> V_11 , V_29 ) ;
F_13 () ;
}
if ( F_44 ( V_61 +
F_40 ( V_65 ) ) ) {
F_45 ( V_5 , V_8 -> V_11 ) ;
F_27 ( & V_8 -> V_10 ) ;
F_28 ( V_8 , V_52 ) ;
}
}
F_13 () ;
}
void * F_46 ( struct V_4 * V_5 , void * V_66 ,
unsigned char V_6 [ V_15 ] )
{
struct V_7 * V_8 ;
if ( ! V_66 ) {
V_8 = F_3 ( & V_5 -> V_14 ,
struct V_7 , V_10 ) ;
if ( V_8 )
F_10 ( V_6 , V_8 -> V_11 ) ;
return V_8 ;
}
V_8 = V_66 ;
F_47 (node, &hsr->node_db, mac_list) {
F_10 ( V_6 , V_8 -> V_11 ) ;
return V_8 ;
}
return NULL ;
}
int F_48 ( struct V_4 * V_5 ,
const unsigned char * V_6 ,
unsigned char V_17 [ V_15 ] ,
unsigned int * V_67 ,
int * V_68 ,
T_1 * V_69 ,
int * V_70 ,
T_1 * V_71 )
{
struct V_7 * V_8 ;
struct V_28 * V_29 ;
unsigned long V_72 ;
F_11 () ;
V_8 = F_6 ( & V_5 -> V_14 , V_6 ) ;
if ( ! V_8 ) {
F_13 () ;
return - V_73 ;
}
F_10 ( V_17 , V_8 -> V_12 ) ;
V_72 = V_25 - V_8 -> V_27 [ V_58 ] ;
if ( V_8 -> V_50 [ V_58 ] )
* V_68 = V_74 ;
#if V_75 <= V_76
else if ( V_72 > F_40 ( V_74 ) )
* V_68 = V_74 ;
#endif
else
* V_68 = F_49 ( V_72 ) ;
V_72 = V_25 - V_8 -> V_27 [ V_59 ] ;
if ( V_8 -> V_50 [ V_59 ] )
* V_70 = V_74 ;
#if V_75 <= V_76
else if ( V_72 > F_40 ( V_74 ) )
* V_70 = V_74 ;
#endif
else
* V_70 = F_49 ( V_72 ) ;
* V_69 = V_8 -> V_21 [ V_59 ] ;
* V_71 = V_8 -> V_21 [ V_58 ] ;
if ( V_8 -> V_51 != V_77 ) {
V_29 = F_39 ( V_5 , V_8 -> V_51 ) ;
* V_67 = V_29 -> V_78 -> V_79 ;
} else {
* V_67 = - 1 ;
}
F_13 () ;
return 0 ;
}
