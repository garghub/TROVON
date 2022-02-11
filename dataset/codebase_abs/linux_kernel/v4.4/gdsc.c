static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_2 -> V_6 , & V_3 ) ;
if ( V_4 )
return V_4 ;
return ! ! ( V_3 & V_7 ) ;
}
static int F_3 ( struct V_1 * V_2 , bool V_8 )
{
int V_4 ;
T_1 V_3 = V_8 ? 0 : V_9 ;
T_1 V_10 = V_8 ? V_7 : 0 ;
unsigned long V_11 ;
V_4 = F_4 ( V_2 -> V_5 , V_2 -> V_6 , V_9 , V_3 ) ;
if ( V_4 )
return V_4 ;
V_11 = V_12 + F_5 ( V_13 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , V_2 -> V_6 , & V_3 ) ;
if ( V_4 )
return V_4 ;
if ( ( V_3 & V_7 ) == V_10 )
return 0 ;
} while ( F_6 ( V_12 , V_11 ) );
V_4 = F_2 ( V_2 -> V_5 , V_2 -> V_6 , & V_3 ) ;
if ( V_4 )
return V_4 ;
if ( ( V_3 & V_7 ) == V_10 )
return 0 ;
return - V_14 ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_16 ; V_15 ++ )
V_2 -> V_17 -> V_18 -> V_19 ( V_2 -> V_17 , V_2 -> V_20 [ V_15 ] ) ;
return 0 ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_16 ; V_15 ++ )
V_2 -> V_17 -> V_18 -> assert ( V_2 -> V_17 , V_2 -> V_20 [ V_15 ] ) ;
return 0 ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
int V_15 ;
T_1 V_21 = V_22 | V_23 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_24 ; V_15 ++ )
F_4 ( V_2 -> V_5 , V_2 -> V_25 [ V_15 ] , V_21 , V_21 ) ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
int V_15 ;
T_1 V_21 = V_22 | V_23 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_24 ; V_15 ++ )
F_4 ( V_2 -> V_5 , V_2 -> V_25 [ V_15 ] , V_21 , 0 ) ;
}
static int F_11 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_12 ( V_27 ) ;
int V_4 ;
if ( V_2 -> V_28 == V_29 )
return F_7 ( V_2 ) ;
V_4 = F_3 ( V_2 , true ) ;
if ( V_4 )
return V_4 ;
if ( V_2 -> V_28 & V_30 )
F_9 ( V_2 ) ;
F_13 ( 1 ) ;
return 0 ;
}
static int F_14 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_12 ( V_27 ) ;
if ( V_2 -> V_28 == V_29 )
return F_8 ( V_2 ) ;
if ( V_2 -> V_28 & V_30 )
F_10 ( V_2 ) ;
return F_3 ( V_2 , false ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_21 , V_3 ;
int V_31 , V_4 ;
V_21 = V_32 | V_33 |
V_34 | V_35 | V_36 ;
V_3 = V_37 | V_38 | V_39 ;
V_4 = F_4 ( V_2 -> V_5 , V_2 -> V_6 , V_21 , V_3 ) ;
if ( V_4 )
return V_4 ;
if ( V_2 -> V_28 == V_29 ) {
V_4 = F_3 ( V_2 , true ) ;
if ( V_4 )
return V_4 ;
}
V_31 = F_1 ( V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_31 || ( V_2 -> V_28 & V_40 ) )
F_9 ( V_2 ) ;
else
F_10 ( V_2 ) ;
V_2 -> V_41 . V_42 = F_14 ;
V_2 -> V_41 . V_43 = F_11 ;
F_16 ( & V_2 -> V_41 , NULL , ! V_31 ) ;
return 0 ;
}
int F_17 ( struct V_44 * V_45 , struct V_1 * * V_46 , T_2 V_47 ,
struct V_48 * V_17 , struct V_5 * V_5 )
{
int V_15 , V_4 ;
struct V_49 * V_50 ;
V_50 = F_18 ( V_45 , sizeof( * V_50 ) , V_51 ) ;
if ( ! V_50 )
return - V_52 ;
V_50 -> V_53 = F_19 ( V_45 , V_47 , sizeof( * V_50 -> V_53 ) ,
V_51 ) ;
if ( ! V_50 -> V_53 )
return - V_52 ;
V_50 -> V_54 = V_47 ;
for ( V_15 = 0 ; V_15 < V_47 ; V_15 ++ ) {
if ( ! V_46 [ V_15 ] )
continue;
V_46 [ V_15 ] -> V_5 = V_5 ;
V_46 [ V_15 ] -> V_17 = V_17 ;
V_4 = F_15 ( V_46 [ V_15 ] ) ;
if ( V_4 )
return V_4 ;
V_50 -> V_53 [ V_15 ] = & V_46 [ V_15 ] -> V_41 ;
}
return F_20 ( V_45 -> V_55 , V_50 ) ;
}
void F_21 ( struct V_44 * V_45 )
{
F_22 ( V_45 -> V_55 ) ;
}
