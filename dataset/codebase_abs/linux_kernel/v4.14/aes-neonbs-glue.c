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
static int F_16 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
struct V_29 * V_6 = F_2 ( V_2 ) ;
struct V_17 V_18 ;
int V_9 , V_32 = 1 ;
V_9 = F_10 ( & V_18 , V_13 , true ) ;
F_4 () ;
while ( V_18 . V_19 >= V_20 ) {
unsigned int V_16 = V_18 . V_19 / V_20 ;
F_17 ( V_18 . V_23 . V_24 . V_25 , V_18 . V_26 . V_24 . V_25 ,
V_6 -> V_31 , V_6 -> V_30 . V_10 , V_16 , V_18 . V_33 ,
V_32 ) ;
V_9 = F_12 ( & V_18 , V_18 . V_19 % V_20 ) ;
V_32 = 0 ;
}
F_6 () ;
return V_9 ;
}
static int F_18 ( struct V_12 * V_13 )
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
F_19 ( V_18 . V_23 . V_24 . V_25 , V_18 . V_26 . V_24 . V_25 ,
V_6 -> V_30 . V_8 , V_6 -> V_30 . V_10 , V_16 ,
V_18 . V_33 ) ;
V_9 = F_12 ( & V_18 ,
V_18 . V_19 - V_16 * V_20 ) ;
}
F_6 () ;
return V_9 ;
}
static int F_20 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_34 * V_6 = F_2 ( V_2 ) ;
int V_9 ;
V_9 = F_3 ( & V_6 -> V_35 , V_3 , V_4 ) ;
if ( V_9 )
return V_9 ;
V_6 -> V_30 . V_10 = 6 + V_4 / 4 ;
F_4 () ;
F_5 ( V_6 -> V_30 . V_8 , V_6 -> V_35 . V_11 , V_6 -> V_30 . V_10 ) ;
F_6 () ;
return 0 ;
}
static int F_21 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 V_18 ;
T_1 V_36 [ V_20 ] ;
int V_9 ;
V_9 = F_10 ( & V_18 , V_13 , true ) ;
F_4 () ;
while ( V_18 . V_19 > 0 ) {
unsigned int V_16 = V_18 . V_19 / V_20 ;
T_1 * V_37 = ( V_18 . V_21 % V_20 ) ? V_36 : NULL ;
if ( V_18 . V_19 < V_18 . V_21 ) {
V_16 = F_11 ( V_16 ,
V_18 . V_22 / V_20 ) ;
V_37 = NULL ;
}
F_22 ( V_18 . V_23 . V_24 . V_25 , V_18 . V_26 . V_24 . V_25 ,
V_6 -> V_8 , V_6 -> V_10 , V_16 , V_18 . V_33 , V_37 ) ;
if ( V_37 ) {
T_1 * V_23 = V_18 . V_23 . V_24 . V_25 + V_16 * V_20 ;
T_1 * V_26 = V_18 . V_26 . V_24 . V_25 + V_16 * V_20 ;
F_23 ( V_23 , V_26 , V_37 ,
V_18 . V_21 % V_20 ) ;
V_9 = F_12 ( & V_18 , 0 ) ;
break;
}
V_9 = F_12 ( & V_18 ,
V_18 . V_19 - V_16 * V_20 ) ;
}
F_6 () ;
return V_9 ;
}
static int F_24 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_38 * V_6 = F_2 ( V_2 ) ;
struct V_7 V_8 ;
int V_9 ;
V_9 = F_25 ( V_2 , V_3 , V_4 ) ;
if ( V_9 )
return V_9 ;
V_4 /= 2 ;
V_9 = F_3 ( & V_8 , V_3 + V_4 , V_4 ) ;
if ( V_9 )
return V_9 ;
memcpy ( V_6 -> V_39 , V_8 . V_11 , sizeof( V_6 -> V_39 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static int F_26 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
struct V_34 * V_6 = F_2 ( V_2 ) ;
if ( ! F_27 () )
return F_28 ( & V_6 -> V_35 , V_13 ) ;
return F_21 ( V_13 ) ;
}
static int F_29 ( struct V_12 * V_13 ,
void (* F_8)( T_1 V_14 [] , T_1 const V_15 [] , T_1 const V_8 [] ,
int V_10 , int V_16 , T_1 V_33 [] ) )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
struct V_38 * V_6 = F_2 ( V_2 ) ;
struct V_17 V_18 ;
int V_9 ;
V_9 = F_10 ( & V_18 , V_13 , true ) ;
F_4 () ;
F_30 ( V_18 . V_33 , V_18 . V_33 , V_6 -> V_39 ,
V_6 -> V_30 . V_10 , 1 , 1 ) ;
while ( V_18 . V_19 >= V_20 ) {
unsigned int V_16 = V_18 . V_19 / V_20 ;
if ( V_18 . V_19 < V_18 . V_21 )
V_16 = F_11 ( V_16 ,
V_18 . V_22 / V_20 ) ;
F_8 ( V_18 . V_23 . V_24 . V_25 , V_18 . V_26 . V_24 . V_25 , V_6 -> V_30 . V_8 ,
V_6 -> V_30 . V_10 , V_16 , V_18 . V_33 ) ;
V_9 = F_12 ( & V_18 ,
V_18 . V_19 - V_16 * V_20 ) ;
}
F_6 () ;
return V_9 ;
}
static int F_31 ( struct V_12 * V_13 )
{
return F_29 ( V_13 , V_40 ) ;
}
static int F_32 ( struct V_12 * V_13 )
{
return F_29 ( V_13 , V_41 ) ;
}
static void F_33 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_34 ( V_43 ) ; V_42 ++ )
if ( V_43 [ V_42 ] )
F_35 ( V_43 [ V_42 ] ) ;
F_36 ( V_44 , F_34 ( V_44 ) ) ;
}
static int T_2 F_37 ( void )
{
struct V_45 * V_46 ;
const char * V_47 ;
const char * V_48 ;
const char * V_49 ;
int V_9 ;
int V_42 ;
if ( ! ( V_50 & V_51 ) )
return - V_52 ;
V_9 = F_38 ( V_44 , F_34 ( V_44 ) ) ;
if ( V_9 )
return V_9 ;
for ( V_42 = 0 ; V_42 < F_34 ( V_44 ) ; V_42 ++ ) {
if ( ! ( V_44 [ V_42 ] . V_53 . V_54 & V_55 ) )
continue;
V_48 = V_44 [ V_42 ] . V_53 . V_56 + 2 ;
V_49 = V_44 [ V_42 ] . V_53 . V_57 + 2 ;
V_47 = V_44 [ V_42 ] . V_53 . V_57 ;
V_46 = F_39 ( V_48 , V_49 , V_47 ) ;
V_9 = F_40 ( V_46 ) ;
if ( F_41 ( V_46 ) )
goto V_58;
V_43 [ V_42 ] = V_46 ;
}
return 0 ;
V_58:
F_33 () ;
return V_9 ;
}
