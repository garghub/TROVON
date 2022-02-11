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
struct V_7 * F_19 ( struct V_13 * V_14 , struct V_28 * V_29 ,
bool V_30 )
{
struct V_7 * V_8 ;
struct V_31 * V_31 ;
T_1 V_21 ;
if ( ! F_20 ( V_29 ) )
return NULL ;
V_31 = (struct V_31 * ) F_21 ( V_29 ) ;
F_7 (node, node_db, mac_list) {
if ( F_5 ( V_8 -> V_11 , V_31 -> V_32 ) )
return V_8 ;
if ( F_5 ( V_8 -> V_12 , V_31 -> V_32 ) )
return V_8 ;
}
if ( ! V_30 )
return NULL ;
if ( V_31 -> V_33 == F_22 ( V_34 ) ) {
V_21 = F_23 ( V_29 ) - 1 ;
} else {
F_4 ( 1 , L_2 , V_35 ) ;
V_21 = 0 ;
}
return F_17 ( V_14 , V_31 -> V_32 , V_21 ) ;
}
void F_24 ( struct V_28 * V_29 , struct V_7 * V_36 ,
struct V_37 * V_38 )
{
struct V_7 * V_39 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
int V_23 ;
F_25 ( V_29 , sizeof( struct V_42 ) ) ;
V_41 = (struct V_40 * ) V_29 -> V_43 ;
if ( F_5 ( F_26 ( V_29 ) -> V_32 , V_41 -> V_11 ) )
goto V_44;
V_14 = & V_38 -> V_5 -> V_14 ;
V_39 = F_6 ( V_14 , V_41 -> V_11 ) ;
if ( ! V_39 )
V_39 = F_17 ( V_14 , V_41 -> V_11 ,
V_45 - 1 ) ;
if ( ! V_39 )
goto V_44;
if ( V_39 == V_36 )
goto V_44;
F_10 ( V_39 -> V_12 , F_26 ( V_29 ) -> V_32 ) ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
if ( ! V_36 -> V_46 [ V_23 ] &&
F_27 ( V_36 -> V_27 [ V_23 ] , V_39 -> V_27 [ V_23 ] ) ) {
V_39 -> V_27 [ V_23 ] = V_36 -> V_27 [ V_23 ] ;
V_39 -> V_46 [ V_23 ] = V_36 -> V_46 [ V_23 ] ;
}
if ( F_1 ( V_36 -> V_21 [ V_23 ] , V_39 -> V_21 [ V_23 ] ) )
V_39 -> V_21 [ V_23 ] = V_36 -> V_21 [ V_23 ] ;
}
V_39 -> V_47 = V_38 -> type ;
F_28 ( & V_36 -> V_10 ) ;
F_29 ( V_36 , V_48 ) ;
V_44:
F_30 ( V_29 , sizeof( struct V_42 ) ) ;
}
void F_31 ( struct V_7 * V_8 , struct V_28 * V_29 )
{
if ( ! F_20 ( V_29 ) ) {
F_4 ( 1 , L_3 , V_35 ) ;
return;
}
memcpy ( & F_26 ( V_29 ) -> V_32 , V_8 -> V_11 , V_15 ) ;
}
void F_32 ( struct V_7 * V_49 , struct V_28 * V_29 ,
struct V_37 * V_50 )
{
struct V_7 * V_51 ;
if ( ! F_20 ( V_29 ) ) {
F_4 ( 1 , L_3 , V_35 ) ;
return;
}
if ( ! F_33 ( F_26 ( V_29 ) -> V_52 ) )
return;
V_51 = F_6 ( & V_50 -> V_5 -> V_14 , F_26 ( V_29 ) -> V_52 ) ;
if ( ! V_51 ) {
F_4 ( 1 , L_4 , V_35 ) ;
return;
}
if ( V_50 -> type != V_51 -> V_47 )
return;
F_10 ( F_26 ( V_29 ) -> V_52 , V_51 -> V_12 ) ;
}
void F_34 ( struct V_7 * V_8 , struct V_37 * V_50 ,
T_1 V_53 )
{
if ( F_35 ( V_53 , V_8 -> V_21 [ V_50 -> type ] ) )
return;
V_8 -> V_27 [ V_50 -> type ] = V_25 ;
V_8 -> V_46 [ V_50 -> type ] = false ;
}
int F_36 ( struct V_37 * V_50 , struct V_7 * V_8 ,
T_1 V_53 )
{
if ( F_37 ( V_53 , V_8 -> V_21 [ V_50 -> type ] ) )
return 1 ;
V_8 -> V_21 [ V_50 -> type ] = V_53 ;
return 0 ;
}
static struct V_37 * F_38 ( struct V_4 * V_5 ,
struct V_7 * V_8 )
{
if ( V_8 -> V_46 [ V_54 ] )
return F_39 ( V_5 , V_54 ) ;
if ( V_8 -> V_46 [ V_55 ] )
return F_39 ( V_5 , V_55 ) ;
if ( F_27 ( V_8 -> V_27 [ V_55 ] ,
V_8 -> V_27 [ V_54 ] +
F_40 ( V_56 ) ) )
return F_39 ( V_5 , V_54 ) ;
if ( F_27 ( V_8 -> V_27 [ V_54 ] ,
V_8 -> V_27 [ V_55 ] +
F_40 ( V_56 ) ) )
return F_39 ( V_5 , V_55 ) ;
return NULL ;
}
void F_41 ( unsigned long V_43 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
struct V_37 * V_50 ;
unsigned long V_57 ;
unsigned long V_58 , V_59 ;
V_5 = (struct V_4 * ) V_43 ;
F_11 () ;
F_7 (node, &hsr->node_db, mac_list) {
V_58 = V_8 -> V_27 [ V_54 ] ;
V_59 = V_8 -> V_27 [ V_55 ] ;
if ( F_27 ( V_25 , V_58 + V_60 / 2 ) )
V_8 -> V_46 [ V_54 ] = true ;
if ( F_27 ( V_25 , V_59 + V_60 / 2 ) )
V_8 -> V_46 [ V_55 ] = true ;
V_57 = V_58 ;
if ( V_8 -> V_46 [ V_54 ] ||
( ! V_8 -> V_46 [ V_55 ] &&
F_27 ( V_59 , V_58 ) ) )
V_57 = V_59 ;
if ( F_42 ( V_57 +
F_40 ( 1.5 * V_56 ) ) ) {
F_11 () ;
V_50 = F_38 ( V_5 , V_8 ) ;
if ( V_50 != NULL )
F_43 ( V_5 , V_8 -> V_11 , V_50 ) ;
F_13 () ;
}
if ( F_44 ( V_57 +
F_40 ( V_61 ) ) ) {
F_45 ( V_5 , V_8 -> V_11 ) ;
F_28 ( & V_8 -> V_10 ) ;
F_29 ( V_8 , V_48 ) ;
}
}
F_13 () ;
}
void * F_46 ( struct V_4 * V_5 , void * V_62 ,
unsigned char V_6 [ V_15 ] )
{
struct V_7 * V_8 ;
if ( ! V_62 ) {
V_8 = F_3 ( & V_5 -> V_14 ,
struct V_7 , V_10 ) ;
if ( V_8 )
F_10 ( V_6 , V_8 -> V_11 ) ;
return V_8 ;
}
V_8 = V_62 ;
F_47 (node, &hsr->node_db, mac_list) {
F_10 ( V_6 , V_8 -> V_11 ) ;
return V_8 ;
}
return NULL ;
}
int F_48 ( struct V_4 * V_5 ,
const unsigned char * V_6 ,
unsigned char V_17 [ V_15 ] ,
unsigned int * V_63 ,
int * V_64 ,
T_1 * V_65 ,
int * V_66 ,
T_1 * V_67 )
{
struct V_7 * V_8 ;
struct V_37 * V_50 ;
unsigned long V_68 ;
F_11 () ;
V_8 = F_6 ( & V_5 -> V_14 , V_6 ) ;
if ( ! V_8 ) {
F_13 () ;
return - V_69 ;
}
F_10 ( V_17 , V_8 -> V_12 ) ;
V_68 = V_25 - V_8 -> V_27 [ V_54 ] ;
if ( V_8 -> V_46 [ V_54 ] )
* V_64 = V_70 ;
#if V_71 <= V_72
else if ( V_68 > F_40 ( V_70 ) )
* V_64 = V_70 ;
#endif
else
* V_64 = F_49 ( V_68 ) ;
V_68 = V_25 - V_8 -> V_27 [ V_55 ] ;
if ( V_8 -> V_46 [ V_55 ] )
* V_66 = V_70 ;
#if V_71 <= V_72
else if ( V_68 > F_40 ( V_70 ) )
* V_66 = V_70 ;
#endif
else
* V_66 = F_49 ( V_68 ) ;
* V_65 = V_8 -> V_21 [ V_55 ] ;
* V_67 = V_8 -> V_21 [ V_54 ] ;
if ( V_8 -> V_47 != V_73 ) {
V_50 = F_39 ( V_5 , V_8 -> V_47 ) ;
* V_63 = V_50 -> V_74 -> V_75 ;
} else {
* V_63 = - 1 ;
}
F_13 () ;
return 0 ;
}
