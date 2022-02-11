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
memcpy ( V_6 -> V_31 , V_8 . V_11 , sizeof( V_6 -> V_31 ) ) ;
F_4 () ;
F_5 ( V_6 -> V_30 . V_8 , V_8 . V_11 , V_6 -> V_30 . V_10 ) ;
F_6 () ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , const T_1 * V_26 , T_1 * V_23 )
{
struct V_29 * V_6 = F_2 ( V_2 ) ;
F_17 ( V_6 -> V_31 , V_6 -> V_30 . V_10 , V_26 , V_23 ) ;
}
static int F_18 ( struct V_12 * V_13 )
{
return F_19 ( V_13 , F_16 ) ;
}
static int F_20 ( struct V_12 * V_13 )
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
F_21 ( V_18 . V_23 . V_24 . V_25 , V_18 . V_26 . V_24 . V_25 ,
V_6 -> V_30 . V_8 , V_6 -> V_30 . V_10 , V_16 ,
V_18 . V_32 ) ;
V_9 = F_12 ( & V_18 ,
V_18 . V_19 - V_16 * V_20 ) ;
}
F_6 () ;
return V_9 ;
}
static int F_22 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 V_18 ;
T_1 V_33 [ V_20 ] ;
int V_9 ;
V_9 = F_10 ( & V_18 , V_13 , true ) ;
F_4 () ;
while ( V_18 . V_19 > 0 ) {
unsigned int V_16 = V_18 . V_19 / V_20 ;
T_1 * V_34 = ( V_18 . V_21 % V_20 ) ? V_33 : NULL ;
if ( V_18 . V_19 < V_18 . V_21 ) {
V_16 = F_11 ( V_16 ,
V_18 . V_22 / V_20 ) ;
V_34 = NULL ;
}
F_23 ( V_18 . V_23 . V_24 . V_25 , V_18 . V_26 . V_24 . V_25 ,
V_6 -> V_8 , V_6 -> V_10 , V_16 , V_18 . V_32 , V_34 ) ;
if ( V_34 ) {
T_1 * V_23 = V_18 . V_23 . V_24 . V_25 + V_16 * V_20 ;
T_1 * V_26 = V_18 . V_26 . V_24 . V_25 + V_16 * V_20 ;
if ( V_23 != V_26 )
memcpy ( V_23 , V_26 , V_18 . V_21 % V_20 ) ;
F_24 ( V_23 , V_34 , V_18 . V_21 % V_20 ) ;
V_9 = F_12 ( & V_18 , 0 ) ;
break;
}
V_9 = F_12 ( & V_18 ,
V_18 . V_19 - V_16 * V_20 ) ;
}
F_6 () ;
return V_9 ;
}
static int F_25 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_35 * V_6 = F_2 ( V_2 ) ;
struct V_7 V_8 ;
int V_9 ;
V_9 = F_26 ( V_2 , V_3 , V_4 ) ;
if ( V_9 )
return V_9 ;
V_4 /= 2 ;
V_9 = F_3 ( & V_8 , V_3 + V_4 , V_4 ) ;
if ( V_9 )
return V_9 ;
memcpy ( V_6 -> V_36 , V_8 . V_11 , sizeof( V_6 -> V_36 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static int F_27 ( struct V_12 * V_13 ,
void (* F_8)( T_1 V_14 [] , T_1 const V_15 [] , T_1 const V_8 [] ,
int V_10 , int V_16 , T_1 V_32 [] ) )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
struct V_35 * V_6 = F_2 ( V_2 ) ;
struct V_17 V_18 ;
int V_9 ;
V_9 = F_10 ( & V_18 , V_13 , true ) ;
F_17 ( V_6 -> V_36 , V_6 -> V_30 . V_10 , V_18 . V_32 , V_18 . V_32 ) ;
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
static int F_28 ( struct V_12 * V_13 )
{
return F_27 ( V_13 , V_37 ) ;
}
static int F_29 ( struct V_12 * V_13 )
{
return F_27 ( V_13 , V_38 ) ;
}
static void F_30 ( void )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < F_31 ( V_40 ) ; V_39 ++ )
if ( V_40 [ V_39 ] )
F_32 ( V_40 [ V_39 ] ) ;
F_33 ( V_41 , F_31 ( V_41 ) ) ;
}
static int T_2 F_34 ( void )
{
struct V_42 * V_43 ;
const char * V_44 ;
const char * V_45 ;
const char * V_46 ;
int V_9 ;
int V_39 ;
if ( ! ( V_47 & V_48 ) )
return - V_49 ;
V_9 = F_35 ( V_41 , F_31 ( V_41 ) ) ;
if ( V_9 )
return V_9 ;
for ( V_39 = 0 ; V_39 < F_31 ( V_41 ) ; V_39 ++ ) {
if ( ! ( V_41 [ V_39 ] . V_50 . V_51 & V_52 ) )
continue;
V_45 = V_41 [ V_39 ] . V_50 . V_53 + 2 ;
V_46 = V_41 [ V_39 ] . V_50 . V_54 + 2 ;
V_44 = V_41 [ V_39 ] . V_50 . V_54 ;
V_43 = F_36 ( V_45 , V_46 , V_44 ) ;
V_9 = F_37 ( V_43 ) ;
if ( F_38 ( V_43 ) )
goto V_55;
V_40 [ V_39 ] = V_43 ;
}
return 0 ;
V_55:
F_30 () ;
return V_9 ;
}
