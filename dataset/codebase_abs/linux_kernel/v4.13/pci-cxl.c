struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
return F_3 ( V_5 -> V_7 ) ;
}
int F_4 ( struct V_2 * V_3 , T_1 V_8 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_12 * V_13 ;
int V_14 ;
V_13 = F_5 ( V_3 ) ;
if ( ! V_13 )
return - V_15 ;
F_6 ( V_13 , L_1 ) ;
V_14 = F_7 ( V_10 -> V_16 , V_8 , V_13 -> V_17 ) ;
if ( V_14 == V_18 )
F_8 ( & V_3 -> V_3 , L_2 ) ;
else if ( V_14 )
F_8 ( & V_3 -> V_3 , L_3 , V_14 ) ;
return V_14 ;
}
int F_9 ( struct V_2 * V_3 , int V_19 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_20 = F_10 ( & V_10 -> V_21 , V_19 ) ;
if ( V_20 < 0 ) {
F_11 ( & V_3 -> V_3 , L_4 ) ;
return - V_22 ;
}
return V_10 -> V_23 + V_20 ;
}
void F_12 ( struct V_2 * V_3 , int V_20 , int V_19 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
F_13 ( & V_10 -> V_21 , V_20 - V_10 -> V_23 , V_19 ) ;
}
void F_14 ( struct V_24 * V_25 ,
struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_26 , V_20 ;
for ( V_26 = 1 ; V_26 < V_27 ; V_26 ++ ) {
if ( ! V_25 -> V_28 [ V_26 ] )
continue;
F_15 ( L_5 ,
V_26 , V_25 -> V_29 [ V_26 ] ,
V_25 -> V_28 [ V_26 ] ) ;
V_20 = V_25 -> V_29 [ V_26 ] - V_10 -> V_23 ;
F_13 ( & V_10 -> V_21 , V_20 ,
V_25 -> V_28 [ V_26 ] ) ;
}
}
int F_16 ( struct V_24 * V_25 ,
struct V_2 * V_3 , int V_19 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_26 , V_20 , V_30 ;
memset ( V_25 , 0 , sizeof( struct V_24 ) ) ;
for ( V_26 = 1 ; V_26 < V_27 && V_19 ; V_26 ++ ) {
V_30 = V_19 ;
while ( V_30 ) {
V_20 = F_10 ( & V_10 -> V_21 , V_30 ) ;
if ( V_20 >= 0 )
break;
V_30 /= 2 ;
}
if ( ! V_30 )
goto V_31;
V_25 -> V_29 [ V_26 ] = V_10 -> V_23 + V_20 ;
V_25 -> V_28 [ V_26 ] = V_30 ;
F_15 ( L_6 ,
V_26 , V_25 -> V_29 [ V_26 ] , V_25 -> V_28 [ V_26 ] ) ;
V_19 -= V_30 ;
}
if ( V_19 )
goto V_31;
return 0 ;
V_31:
F_14 ( V_25 , V_3 ) ;
return - V_22 ;
}
int F_17 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
return V_10 -> V_21 . V_32 ;
}
int F_18 ( struct V_2 * V_3 , unsigned int V_20 ,
unsigned int V_33 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_34 = V_20 - V_10 -> V_23 ;
struct V_12 * V_13 ;
int V_14 ;
if ( ! ( V_13 = F_5 ( V_3 ) ) )
return - V_15 ;
V_14 = F_19 ( V_10 -> V_16 , V_13 -> V_17 , V_34 ) ;
if ( V_14 ) {
F_20 ( V_13 , L_7
L_8 ,
F_21 ( V_3 ) , V_14 , V_10 -> V_23 , V_20 , V_34 ) ;
return - V_35 ;
}
F_22 ( V_10 , V_33 ) ;
return 0 ;
}
static inline int F_23 ( void )
{
struct V_36 * V_37 ;
F_24 ( & V_38 ) ;
V_37 = F_25 ( L_9 ) ;
if ( V_37 )
F_26 ( V_37 ) ;
F_27 ( & V_38 ) ;
if ( ! V_37 )
return - V_15 ;
return 0 ;
}
static inline int F_23 ( void ) { return 0 ; }
int F_28 ( struct V_4 * V_5 , bool V_39 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_14 ;
if ( ! V_39 ) {
return - V_40 ;
}
V_14 = F_23 () ;
if ( V_14 )
return V_14 ;
V_10 -> V_41 |= V_42 ;
V_5 -> V_43 = V_44 ;
return 0 ;
}
bool F_29 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
return ! ! ( V_10 -> V_41 & V_42 ) ;
}
struct V_45 * F_30 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
return (struct V_45 * ) V_10 -> V_45 ;
}
void F_31 ( struct V_2 * V_3 , struct V_45 * V_46 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
V_10 -> V_45 = V_46 ;
}
bool F_32 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_45 * V_46 = V_10 -> V_45 ;
if ( ! F_33 ( V_3 ) )
return false ;
if ( F_34 ( V_3 -> V_47 ) == 0 )
return true ;
if ( ! V_46 ) {
F_35 ( & V_3 -> V_3 , L_10 ) ;
return false ;
}
F_36 ( & V_3 -> V_3 , L_11 ) ;
F_37 ( V_46 ) ;
return F_38 ( V_3 , V_46 ) ;
}
void F_39 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_45 * V_46 = V_10 -> V_45 ;
if ( F_34 ( V_3 -> V_47 ) == 0 )
return;
F_40 ( V_3 ) ;
F_41 ( V_46 ) ;
}
int F_42 ( struct V_2 * V_48 , int V_49 , int type )
{
struct V_4 * V_5 = F_2 ( V_48 -> V_6 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_50 * V_51 ;
struct V_52 * V_53 = NULL ;
unsigned int V_33 ;
int V_20 ;
int V_54 = 0 ;
int V_14 ;
if ( F_43 ( ! V_10 ) || ! V_10 -> V_21 . V_55 )
return - V_15 ;
if ( V_48 -> V_56 && ! V_10 -> V_57 )
return - V_15 ;
V_14 = F_44 ( V_48 , V_49 , type ) ;
if ( V_14 )
return V_14 ;
F_45 (entry, pdev) {
if ( ! V_51 -> V_58 . V_59 && ! V_10 -> V_57 ) {
F_46 ( L_12 ,
F_21 ( V_48 ) ) ;
return - V_60 ;
}
V_20 = F_47 ( V_48 , & V_53 , & V_54 ) ;
if ( F_43 ( V_20 <= 0 ) )
return ( V_20 ? V_20 : - V_61 ) ;
V_33 = F_48 ( NULL , V_20 ) ;
if ( ! V_33 ) {
F_46 ( L_13 ,
F_21 ( V_48 ) ) ;
return - V_61 ;
}
V_14 = F_18 ( V_48 , V_20 , V_33 ) ;
if ( V_14 ) {
F_46 ( L_14 , F_21 ( V_48 ) ) ;
F_49 ( V_33 ) ;
return V_14 ;
}
F_50 ( V_33 , V_51 ) ;
}
return 0 ;
}
void F_51 ( struct V_2 * V_48 )
{
struct V_4 * V_5 = F_2 ( V_48 -> V_6 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_50 * V_51 ;
T_2 V_20 ;
if ( F_43 ( ! V_10 ) )
return;
F_45 (entry, pdev) {
if ( ! V_51 -> V_62 )
continue;
V_20 = F_52 ( V_51 -> V_62 ) ;
F_50 ( V_51 -> V_62 , NULL ) ;
F_49 ( V_51 -> V_62 ) ;
}
F_53 ( V_48 ) ;
}
