static void F_1 ( const char * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_5 = V_3 -> V_6 [ V_6 ] . V_8 ;
if ( ! V_5 )
continue;
F_2 ( V_9 L_1
L_2 , V_1 , V_6 ,
F_3 ( V_5 -> V_10 ) ,
F_3 ( V_5 -> V_11 ) ,
F_3 ( V_5 -> V_12 ) ,
F_3 ( V_5 -> V_13 ) ,
F_3 ( V_5 -> V_14 ) ,
F_3 ( V_5 -> V_15 ) ) ;
}
}
static inline unsigned int F_4 ( unsigned int V_16 , unsigned int V_17 )
{
return V_16 ? F_5 ( V_16 , V_17 ) : 0 ;
}
static unsigned int F_6 ( unsigned int V_18 , unsigned int V_17 ,
unsigned int * V_19 )
{
unsigned int V_20 = F_4 ( V_18 , V_17 ) ;
if ( V_20 > 0xf )
* V_19 = - V_21 ;
return V_20 ;
}
static int F_7 ( struct V_22 * V_23 ,
struct V_4 * V_5 )
{
unsigned int V_24 = V_23 -> V_25 . V_26 ;
int V_19 = 0 ;
V_5 -> V_27 = F_6 ( V_5 -> V_10 , V_24 , & V_19 ) ;
V_5 -> V_28 = F_6 ( V_5 -> V_11 , V_24 , & V_19 ) ;
V_5 -> V_29 = F_6 ( V_5 -> V_12 , V_24 , & V_19 ) ;
V_5 -> V_30 = F_6 ( V_5 -> V_13 , V_24 , & V_19 ) ;
V_5 -> V_31 = F_6 ( V_5 -> V_14 , V_24 , & V_19 ) ;
V_5 -> V_32 = F_6 ( V_5 -> V_15 , V_24 , & V_19 ) ;
return V_19 ;
}
void F_8 ( struct V_33 * V_34 ,
struct V_22 * V_23 ,
union V_35 * V_36 )
{
struct V_4 * V_5 = V_36 -> V_8 ;
F_9 ( V_34 ,
L_3
L_2 ,
F_3 ( V_5 -> V_10 ) ,
F_3 ( V_5 -> V_11 ) ,
F_3 ( V_5 -> V_12 ) ,
F_3 ( V_5 -> V_13 ) ,
F_3 ( V_5 -> V_14 ) ,
F_3 ( V_5 -> V_15 ) ) ;
}
int F_10 ( struct V_22 * V_23 ,
struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
int V_20 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_5 = V_3 -> V_6 [ V_6 ] . V_8 ;
if ( ! V_5 )
continue;
V_20 = F_7 ( V_23 , V_5 ) ;
if ( V_20 ) {
F_2 ( V_37 L_4 ,
V_38 , V_6 ) ;
goto V_19;
}
}
return 0 ;
V_19:
return V_20 ;
}
void F_11 ( struct V_22 * V_23 ,
struct V_2 * V_3 )
{
struct V_4 * V_5 ;
void T_1 * V_39 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_5 = V_3 -> V_6 [ V_6 ] . V_8 ;
if ( ! V_5 )
continue;
V_39 = F_12 ( V_6 ) ;
F_13 ( V_5 -> V_27 , V_39 + V_40 ) ;
F_13 ( V_5 -> V_28 , V_39 + V_41 ) ;
F_13 ( V_5 -> V_29 , V_39 + V_42 ) ;
F_13 ( V_5 -> V_30 , V_39 + V_43 ) ;
F_13 ( V_5 -> V_31 , V_39 + V_44 ) ;
F_13 ( V_5 -> V_32 , V_39 + V_45 ) ;
}
}
static inline unsigned int F_14 ( unsigned int clock , T_2 V_46 )
{
return ( V_46 & 0xf ) * clock ;
}
static void F_15 ( struct V_22 * V_23 ,
struct V_4 * V_5 ,
unsigned int V_6 )
{
unsigned long V_47 = V_23 -> V_25 . V_26 ;
void T_1 * V_39 = F_12 ( V_6 ) ;
V_5 -> V_10 = F_14 ( V_47 , F_16 ( V_39 + V_40 ) ) ;
V_5 -> V_11 = F_14 ( V_47 , F_16 ( V_39 + V_41 ) ) ;
V_5 -> V_13 = F_14 ( V_47 , F_16 ( V_39 + V_43 ) ) ;
V_5 -> V_14 = F_14 ( V_47 , F_16 ( V_39 + V_44 ) ) ;
V_5 -> V_15 = F_14 ( V_47 , F_16 ( V_39 + V_45 ) ) ;
}
static inline bool F_17 ( unsigned int V_6 , T_2 V_48 )
{
if ( V_6 < 2 )
return true ;
return ! ( V_48 & ( 1 << V_6 ) ) ;
}
int F_18 ( struct V_22 * V_23 ,
struct V_2 * V_49 )
{
struct V_4 * V_5 ;
T_2 V_48 = F_16 ( V_50 ) ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
if ( ! F_17 ( V_6 , V_48 ) )
continue;
V_5 = F_19 ( sizeof( struct V_4 ) , V_51 ) ;
if ( ! V_5 ) {
F_2 ( V_37 L_5 , V_38 ) ;
return - V_52 ;
}
V_49 -> V_6 [ V_6 ] . V_8 = V_5 ;
F_15 ( V_23 , V_5 , V_6 ) ;
}
F_1 ( L_6 , V_49 ) ;
return 0 ;
}
void F_20 ( struct V_22 * V_23 )
{
struct V_53 * V_54 = V_23 -> V_54 ;
T_2 V_55 ;
F_21 ( V_54 == NULL ) ;
V_55 = ( V_23 -> V_25 . V_24 / 100 ) * ( V_54 -> V_55 / 10 ) ;
V_55 = F_5 ( V_55 , ( 1000 * 1000 ) ) ;
V_55 &= ( ( 1 << 16 ) - 1 ) ;
F_22 ( L_7 , V_38 , ( unsigned int ) V_55 ) ;
F_13 ( V_55 , V_56 ) ;
}
