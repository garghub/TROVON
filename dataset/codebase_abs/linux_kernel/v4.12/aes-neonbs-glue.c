static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 V_8 ;
int V_9 ;
V_9 = F_3 ( & V_8 , V_3 , V_4 ) ;
if ( V_9 )
return V_9 ;
V_6 -> V_10 = 6 + V_4 / 4 ;
F_4 () ;
F_5 ( V_6 -> V_8 , V_8 . V_11 , V_6 -> V_10 ) ;
F_6 () ;
return 0 ;
}
static int F_7 ( struct V_12 * V_13 ,
void (* F_8)( T_1 V_14 [] , T_1 const V_15 [] , T_1 const V_8 [] ,
int V_10 , int V_16 ) )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 V_18 ;
int V_9 ;
V_9 = F_10 ( & V_18 , V_13 , true ) ;
F_4 () ;
while ( V_18 . V_19 >= V_20 ) {
unsigned int V_16 = V_18 . V_19 / V_20 ;
if ( V_18 . V_19 < V_18 . V_21 )
V_16 = F_11 ( V_16 ,
V_18 . V_22 / V_20 ) ;
F_8 ( V_18 . V_23 . V_24 . V_25 , V_18 . V_26 . V_24 . V_25 , V_6 -> V_8 ,
V_6 -> V_10 , V_16 ) ;
V_9 = F_12 ( & V_18 ,
V_18 . V_19 - V_16 * V_20 ) ;
}
F_6 () ;
return V_9 ;
}
static int F_13 ( struct V_12 * V_13 )
{
return F_7 ( V_13 , V_27 ) ;
}
static int F_14 ( struct V_12 * V_13 )
{
return F_7 ( V_13 , V_28 ) ;
}
static int F_15 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_29 * V_6 = F_2 ( V_2 ) ;
struct V_7 V_8 ;
int V_9 ;
V_9 = F_3 ( & V_8 , V_3 , V_4 ) ;
if ( V_9 )
return V_9 ;
V_6 -> V_30 . V_10 = 6 + V_4 / 4 ;
F_4 () ;
F_5 ( V_6 -> V_30 . V_8 , V_8 . V_11 , V_6 -> V_30 . V_10 ) ;
F_6 () ;
return F_16 ( V_6 -> V_31 , V_3 , V_4 ) ;
}
static void F_17 ( struct V_1 * V_2 , const T_1 * V_26 , T_1 * V_23 )
{
struct V_29 * V_6 = F_2 ( V_2 ) ;
F_18 ( V_6 -> V_31 , V_23 , V_26 ) ;
}
static int F_19 ( struct V_12 * V_13 )
{
return F_20 ( V_13 , F_17 ) ;
}
static int F_21 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
struct V_29 * V_6 = F_2 ( V_2 ) ;
struct V_17 V_18 ;
int V_9 ;
V_9 = F_10 ( & V_18 , V_13 , true ) ;
F_4 () ;
while ( V_18 . V_19 >= V_20 ) {
unsigned int V_16 = V_18 . V_19 / V_20 ;
if ( V_18 . V_19 < V_18 . V_21 )
V_16 = F_11 ( V_16 ,
V_18 . V_22 / V_20 ) ;
F_22 ( V_18 . V_23 . V_24 . V_25 , V_18 . V_26 . V_24 . V_25 ,
V_6 -> V_30 . V_8 , V_6 -> V_30 . V_10 , V_16 ,
V_18 . V_32 ) ;
V_9 = F_12 ( & V_18 ,
V_18 . V_19 - V_16 * V_20 ) ;
}
F_6 () ;
return V_9 ;
}
static int F_23 ( struct V_33 * V_2 )
{
struct V_29 * V_6 = F_24 ( V_2 ) ;
V_6 -> V_31 = F_25 ( L_1 , 0 , 0 ) ;
if ( F_26 ( V_6 -> V_31 ) )
return F_27 ( V_6 -> V_31 ) ;
return 0 ;
}
static void F_28 ( struct V_33 * V_2 )
{
struct V_29 * V_6 = F_24 ( V_2 ) ;
F_29 ( V_6 -> V_31 ) ;
}
static int F_30 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 V_18 ;
T_1 V_34 [ V_20 ] ;
int V_9 ;
V_9 = F_10 ( & V_18 , V_13 , true ) ;
F_4 () ;
while ( V_18 . V_19 > 0 ) {
unsigned int V_16 = V_18 . V_19 / V_20 ;
T_1 * V_35 = ( V_18 . V_21 % V_20 ) ? V_34 : NULL ;
if ( V_18 . V_19 < V_18 . V_21 ) {
V_16 = F_11 ( V_16 ,
V_18 . V_22 / V_20 ) ;
V_35 = NULL ;
}
F_31 ( V_18 . V_23 . V_24 . V_25 , V_18 . V_26 . V_24 . V_25 ,
V_6 -> V_8 , V_6 -> V_10 , V_16 , V_18 . V_32 , V_35 ) ;
if ( V_35 ) {
T_1 * V_23 = V_18 . V_23 . V_24 . V_25 + V_16 * V_20 ;
T_1 * V_26 = V_18 . V_26 . V_24 . V_25 + V_16 * V_20 ;
if ( V_23 != V_26 )
memcpy ( V_23 , V_26 , V_18 . V_21 % V_20 ) ;
F_32 ( V_23 , V_35 , V_18 . V_21 % V_20 ) ;
V_9 = F_12 ( & V_18 , 0 ) ;
break;
}
V_9 = F_12 ( & V_18 ,
V_18 . V_19 - V_16 * V_20 ) ;
}
F_6 () ;
return V_9 ;
}
static int F_33 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_36 * V_6 = F_2 ( V_2 ) ;
int V_9 ;
V_9 = F_34 ( V_2 , V_3 , V_4 ) ;
if ( V_9 )
return V_9 ;
V_4 /= 2 ;
V_9 = F_16 ( V_6 -> V_37 , V_3 + V_4 , V_4 ) ;
if ( V_9 )
return V_9 ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static int F_35 ( struct V_33 * V_2 )
{
struct V_36 * V_6 = F_24 ( V_2 ) ;
V_6 -> V_37 = F_25 ( L_1 , 0 , 0 ) ;
if ( F_26 ( V_6 -> V_37 ) )
return F_27 ( V_6 -> V_37 ) ;
return 0 ;
}
static void F_36 ( struct V_33 * V_2 )
{
struct V_36 * V_6 = F_24 ( V_2 ) ;
F_29 ( V_6 -> V_37 ) ;
}
static int F_37 ( struct V_12 * V_13 ,
void (* F_8)( T_1 V_14 [] , T_1 const V_15 [] , T_1 const V_8 [] ,
int V_10 , int V_16 , T_1 V_32 [] ) )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
struct V_36 * V_6 = F_2 ( V_2 ) ;
struct V_17 V_18 ;
int V_9 ;
V_9 = F_10 ( & V_18 , V_13 , true ) ;
F_18 ( V_6 -> V_37 , V_18 . V_32 , V_18 . V_32 ) ;
F_4 () ;
while ( V_18 . V_19 >= V_20 ) {
unsigned int V_16 = V_18 . V_19 / V_20 ;
if ( V_18 . V_19 < V_18 . V_21 )
V_16 = F_11 ( V_16 ,
V_18 . V_22 / V_20 ) ;
F_8 ( V_18 . V_23 . V_24 . V_25 , V_18 . V_26 . V_24 . V_25 , V_6 -> V_30 . V_8 ,
V_6 -> V_30 . V_10 , V_16 , V_18 . V_32 ) ;
V_9 = F_12 ( & V_18 ,
V_18 . V_19 - V_16 * V_20 ) ;
}
F_6 () ;
return V_9 ;
}
static int F_38 ( struct V_12 * V_13 )
{
return F_37 ( V_13 , V_38 ) ;
}
static int F_39 ( struct V_12 * V_13 )
{
return F_37 ( V_13 , V_39 ) ;
}
static void F_40 ( void )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < F_41 ( V_41 ) ; V_40 ++ )
if ( V_41 [ V_40 ] )
F_42 ( V_41 [ V_40 ] ) ;
F_43 ( V_42 , F_41 ( V_42 ) ) ;
}
static int T_2 F_44 ( void )
{
struct V_43 * V_44 ;
const char * V_45 ;
const char * V_46 ;
const char * V_47 ;
int V_9 ;
int V_40 ;
if ( ! ( V_48 & V_49 ) )
return - V_50 ;
V_9 = F_45 ( V_42 , F_41 ( V_42 ) ) ;
if ( V_9 )
return V_9 ;
for ( V_40 = 0 ; V_40 < F_41 ( V_42 ) ; V_40 ++ ) {
if ( ! ( V_42 [ V_40 ] . V_51 . V_52 & V_53 ) )
continue;
V_46 = V_42 [ V_40 ] . V_51 . V_54 + 2 ;
V_47 = V_42 [ V_40 ] . V_51 . V_55 + 2 ;
V_45 = V_42 [ V_40 ] . V_51 . V_55 ;
V_44 = F_46 ( V_46 , V_47 , V_45 ) ;
V_9 = F_27 ( V_44 ) ;
if ( F_26 ( V_44 ) )
goto V_56;
V_41 [ V_40 ] = V_44 ;
}
return 0 ;
V_56:
F_40 () ;
return V_9 ;
}
