static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_3 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return ! ! ( V_4 & V_7 ) ;
}
static int F_3 ( struct V_1 * V_2 , bool V_8 )
{
T_1 V_4 = V_8 ? V_9 : 0 ;
return F_4 ( V_2 -> V_6 , V_2 -> V_10 , V_9 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 , bool V_8 )
{
T_2 V_11 ;
V_11 = F_6 () ;
do {
if ( F_1 ( V_2 , V_3 ) == V_8 )
return 0 ;
} while ( F_7 ( F_6 () , V_11 ) < V_12 );
if ( F_1 ( V_2 , V_3 ) == V_8 )
return 0 ;
return - V_13 ;
}
static int F_8 ( struct V_1 * V_2 , bool V_8 )
{
int V_5 ;
T_1 V_4 = V_8 ? 0 : V_14 ;
unsigned int V_15 = V_2 -> V_10 ;
V_5 = F_4 ( V_2 -> V_6 , V_2 -> V_10 , V_14 , V_4 ) ;
if ( V_5 )
return V_5 ;
if ( ( V_2 -> V_16 & V_17 ) && ! V_8 ) {
F_9 ( V_12 ) ;
return 0 ;
}
if ( V_2 -> V_18 ) {
V_15 = V_2 -> V_18 ;
F_9 ( 1 ) ;
}
return F_5 ( V_2 , V_15 , V_8 ) ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ )
V_2 -> V_21 -> V_22 -> V_23 ( V_2 -> V_21 , V_2 -> V_24 [ V_19 ] ) ;
return 0 ;
}
static inline int F_11 ( struct V_1 * V_2 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ )
V_2 -> V_21 -> V_22 -> assert ( V_2 -> V_21 , V_2 -> V_24 [ V_19 ] ) ;
return 0 ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
int V_19 ;
T_1 V_25 = V_26 | V_27 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_28 ; V_19 ++ )
F_4 ( V_2 -> V_6 , V_2 -> V_29 [ V_19 ] , V_25 , V_25 ) ;
}
static inline void F_13 ( struct V_1 * V_2 )
{
int V_19 ;
T_1 V_25 = V_26 | V_27 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_28 ; V_19 ++ )
F_4 ( V_2 -> V_6 , V_2 -> V_29 [ V_19 ] , V_25 , 0 ) ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_6 , V_2 -> V_30 ,
V_31 , 0 ) ;
}
static inline void F_15 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_6 , V_2 -> V_30 ,
V_31 , 1 ) ;
}
static int F_16 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_17 ( V_33 ) ;
int V_5 ;
if ( V_2 -> V_34 == V_35 )
return F_10 ( V_2 ) ;
if ( V_2 -> V_16 & V_36 )
F_14 ( V_2 ) ;
V_5 = F_8 ( V_2 , true ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_34 & V_37 )
F_12 ( V_2 ) ;
F_9 ( 1 ) ;
if ( V_2 -> V_16 & V_38 ) {
V_5 = F_3 ( V_2 , true ) ;
if ( V_5 )
return V_5 ;
F_9 ( 1 ) ;
}
return 0 ;
}
static int F_18 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_17 ( V_33 ) ;
int V_5 ;
if ( V_2 -> V_34 == V_35 )
return F_11 ( V_2 ) ;
if ( V_2 -> V_16 & V_38 ) {
unsigned int V_3 ;
V_5 = F_3 ( V_2 , false ) ;
if ( V_5 < 0 )
return V_5 ;
F_9 ( 1 ) ;
V_3 = V_2 -> V_18 ? V_2 -> V_18 : V_2 -> V_10 ;
V_5 = F_5 ( V_2 , V_3 , true ) ;
if ( V_5 )
return V_5 ;
}
if ( V_2 -> V_34 & V_37 )
F_13 ( V_2 ) ;
V_5 = F_8 ( V_2 , false ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_16 & V_36 )
F_15 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
T_1 V_25 , V_4 ;
int V_39 , V_5 ;
unsigned int V_3 ;
V_25 = V_9 | V_40 |
V_41 | V_42 | V_43 ;
V_4 = V_44 | V_45 | V_46 ;
V_5 = F_4 ( V_2 -> V_6 , V_2 -> V_10 , V_25 , V_4 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_34 == V_35 ) {
V_5 = F_8 ( V_2 , true ) ;
if ( V_5 )
return V_5 ;
}
V_3 = V_2 -> V_18 ? V_2 -> V_18 : V_2 -> V_10 ;
V_39 = F_1 ( V_2 , V_3 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( ( V_2 -> V_16 & V_17 ) && V_39 )
F_16 ( & V_2 -> V_47 ) ;
if ( V_39 || ( V_2 -> V_34 & V_48 ) )
F_12 ( V_2 ) ;
else
F_13 ( V_2 ) ;
V_2 -> V_47 . V_49 = F_18 ;
V_2 -> V_47 . V_50 = F_16 ;
F_20 ( & V_2 -> V_47 , NULL , ! V_39 ) ;
return 0 ;
}
int F_21 ( struct V_51 * V_52 ,
struct V_53 * V_21 , struct V_6 * V_6 )
{
int V_19 , V_5 ;
struct V_54 * V_55 ;
struct V_56 * V_57 = V_52 -> V_57 ;
struct V_1 * * V_58 = V_52 -> V_58 ;
T_3 V_59 = V_52 -> V_59 ;
V_55 = F_22 ( V_57 , sizeof( * V_55 ) , V_60 ) ;
if ( ! V_55 )
return - V_61 ;
V_55 -> V_62 = F_23 ( V_57 , V_59 , sizeof( * V_55 -> V_62 ) ,
V_60 ) ;
if ( ! V_55 -> V_62 )
return - V_61 ;
V_55 -> V_63 = V_59 ;
for ( V_19 = 0 ; V_19 < V_59 ; V_19 ++ ) {
if ( ! V_58 [ V_19 ] )
continue;
V_58 [ V_19 ] -> V_6 = V_6 ;
V_58 [ V_19 ] -> V_21 = V_21 ;
V_5 = F_19 ( V_58 [ V_19 ] ) ;
if ( V_5 )
return V_5 ;
V_55 -> V_62 [ V_19 ] = & V_58 [ V_19 ] -> V_47 ;
}
for ( V_19 = 0 ; V_19 < V_59 ; V_19 ++ ) {
if ( ! V_58 [ V_19 ] )
continue;
if ( V_58 [ V_19 ] -> V_64 )
F_24 ( V_58 [ V_19 ] -> V_64 , & V_58 [ V_19 ] -> V_47 ) ;
}
return F_25 ( V_57 -> V_65 , V_55 ) ;
}
void F_26 ( struct V_51 * V_52 )
{
int V_19 ;
struct V_56 * V_57 = V_52 -> V_57 ;
struct V_1 * * V_58 = V_52 -> V_58 ;
T_3 V_59 = V_52 -> V_59 ;
for ( V_19 = 0 ; V_19 < V_59 ; V_19 ++ ) {
if ( ! V_58 [ V_19 ] )
continue;
if ( V_58 [ V_19 ] -> V_64 )
F_27 ( V_58 [ V_19 ] -> V_64 , & V_58 [ V_19 ] -> V_47 ) ;
}
F_28 ( V_57 -> V_65 ) ;
}
