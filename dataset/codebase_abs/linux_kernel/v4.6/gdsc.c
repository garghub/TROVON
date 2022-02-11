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
int V_5 ;
T_1 V_4 = V_8 ? 0 : V_9 ;
T_2 V_10 ;
unsigned int V_11 = V_2 -> V_12 ;
V_5 = F_4 ( V_2 -> V_6 , V_2 -> V_12 , V_9 , V_4 ) ;
if ( V_5 )
return V_5 ;
if ( ( V_2 -> V_13 & V_14 ) && ! V_8 ) {
F_5 ( V_15 ) ;
return 0 ;
}
if ( V_2 -> V_16 ) {
V_11 = V_2 -> V_16 ;
F_5 ( 1 ) ;
}
V_10 = F_6 () ;
do {
if ( F_1 ( V_2 , V_11 ) == V_8 )
return 0 ;
} while ( F_7 ( F_6 () , V_10 ) < V_15 );
if ( F_1 ( V_2 , V_11 ) == V_8 )
return 0 ;
return - V_17 ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 ; V_18 ++ )
V_2 -> V_20 -> V_21 -> V_22 ( V_2 -> V_20 , V_2 -> V_23 [ V_18 ] ) ;
return 0 ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 ; V_18 ++ )
V_2 -> V_20 -> V_21 -> assert ( V_2 -> V_20 , V_2 -> V_23 [ V_18 ] ) ;
return 0 ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
int V_18 ;
T_1 V_24 = V_25 | V_26 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_27 ; V_18 ++ )
F_4 ( V_2 -> V_6 , V_2 -> V_28 [ V_18 ] , V_24 , V_24 ) ;
}
static inline void F_11 ( struct V_1 * V_2 )
{
int V_18 ;
T_1 V_24 = V_25 | V_26 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_27 ; V_18 ++ )
F_4 ( V_2 -> V_6 , V_2 -> V_28 [ V_18 ] , V_24 , 0 ) ;
}
static int F_12 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_13 ( V_30 ) ;
int V_5 ;
if ( V_2 -> V_31 == V_32 )
return F_8 ( V_2 ) ;
V_5 = F_3 ( V_2 , true ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_31 & V_33 )
F_10 ( V_2 ) ;
F_5 ( 1 ) ;
return 0 ;
}
static int F_14 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_13 ( V_30 ) ;
if ( V_2 -> V_31 == V_32 )
return F_9 ( V_2 ) ;
if ( V_2 -> V_31 & V_33 )
F_11 ( V_2 ) ;
return F_3 ( V_2 , false ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_24 , V_4 ;
int V_34 , V_5 ;
unsigned int V_3 ;
V_24 = V_35 | V_36 |
V_37 | V_38 | V_39 ;
V_4 = V_40 | V_41 | V_42 ;
V_5 = F_4 ( V_2 -> V_6 , V_2 -> V_12 , V_24 , V_4 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_31 == V_32 ) {
V_5 = F_3 ( V_2 , true ) ;
if ( V_5 )
return V_5 ;
}
V_3 = V_2 -> V_16 ? V_2 -> V_16 : V_2 -> V_12 ;
V_34 = F_1 ( V_2 , V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( ( V_2 -> V_13 & V_14 ) && V_34 )
F_12 ( & V_2 -> V_43 ) ;
if ( V_34 || ( V_2 -> V_31 & V_44 ) )
F_10 ( V_2 ) ;
else
F_11 ( V_2 ) ;
V_2 -> V_43 . V_45 = F_14 ;
V_2 -> V_43 . V_46 = F_12 ;
F_16 ( & V_2 -> V_43 , NULL , ! V_34 ) ;
return 0 ;
}
int F_17 ( struct V_47 * V_48 ,
struct V_49 * V_20 , struct V_6 * V_6 )
{
int V_18 , V_5 ;
struct V_50 * V_51 ;
struct V_52 * V_53 = V_48 -> V_53 ;
struct V_1 * * V_54 = V_48 -> V_54 ;
T_3 V_55 = V_48 -> V_55 ;
V_51 = F_18 ( V_53 , sizeof( * V_51 ) , V_56 ) ;
if ( ! V_51 )
return - V_57 ;
V_51 -> V_58 = F_19 ( V_53 , V_55 , sizeof( * V_51 -> V_58 ) ,
V_56 ) ;
if ( ! V_51 -> V_58 )
return - V_57 ;
V_51 -> V_59 = V_55 ;
for ( V_18 = 0 ; V_18 < V_55 ; V_18 ++ ) {
if ( ! V_54 [ V_18 ] )
continue;
V_54 [ V_18 ] -> V_6 = V_6 ;
V_54 [ V_18 ] -> V_20 = V_20 ;
V_5 = F_15 ( V_54 [ V_18 ] ) ;
if ( V_5 )
return V_5 ;
V_51 -> V_58 [ V_18 ] = & V_54 [ V_18 ] -> V_43 ;
}
for ( V_18 = 0 ; V_18 < V_55 ; V_18 ++ ) {
if ( ! V_54 [ V_18 ] )
continue;
if ( V_54 [ V_18 ] -> V_60 )
F_20 ( V_54 [ V_18 ] -> V_60 , & V_54 [ V_18 ] -> V_43 ) ;
}
return F_21 ( V_53 -> V_61 , V_51 ) ;
}
void F_22 ( struct V_47 * V_48 )
{
int V_18 ;
struct V_52 * V_53 = V_48 -> V_53 ;
struct V_1 * * V_54 = V_48 -> V_54 ;
T_3 V_55 = V_48 -> V_55 ;
for ( V_18 = 0 ; V_18 < V_55 ; V_18 ++ ) {
if ( ! V_54 [ V_18 ] )
continue;
if ( V_54 [ V_18 ] -> V_60 )
F_23 ( V_54 [ V_18 ] -> V_60 , & V_54 [ V_18 ] -> V_43 ) ;
}
F_24 ( V_53 -> V_61 ) ;
}
