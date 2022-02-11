static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = V_4 * 8 ;
if ( F_3 ( V_3 , V_7 , & V_6 -> V_8 ) ) {
F_4 ( V_2 , V_9 ) ;
return - V_10 ;
}
V_6 -> V_11 . V_12 = V_6 -> V_8 ;
F_5 ( V_3 , V_7 , & V_6 -> V_11 . V_12 ) ;
V_6 -> V_11 . V_13 = 0 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_14 * V_6 = F_2 ( V_2 ) ;
int V_7 = V_4 * 8 ;
if ( F_3 ( V_3 , V_7 , & V_6 -> V_8 . V_12 ) ) {
F_4 ( V_2 , V_9 ) ;
return - V_10 ;
}
V_6 -> V_8 . V_13 = 0 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_15 * V_6 = F_2 ( V_2 ) ;
int V_7 = V_4 * 4 ;
int V_16 ;
V_16 = F_8 ( V_2 , V_3 , V_4 ) ;
if ( V_16 )
return V_16 ;
if ( F_3 ( V_3 , V_7 , & V_6 -> V_8 . V_12 ) ) {
F_4 ( V_2 , V_9 ) ;
return - V_10 ;
}
V_6 -> V_11 . V_12 = V_6 -> V_8 . V_12 ;
F_5 ( V_3 , V_7 , & V_6 -> V_11 . V_12 ) ;
F_3 ( V_3 + V_4 / 2 , V_7 , & V_6 -> V_17 ) ;
V_6 -> V_8 . V_13 = V_6 -> V_11 . V_13 = 0 ;
return 0 ;
}
static inline void F_9 ( struct V_1 * V_2 ,
const T_1 * V_18 , T_1 * V_19 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_10 ( V_18 , V_19 , & V_6 -> V_8 ) ;
}
static int F_11 ( struct V_20 * V_21 )
{
return F_12 ( V_21 , F_9 ) ;
}
static inline void F_13 ( struct V_1 * V_2 ,
const T_1 * V_18 , T_1 * V_19 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_14 ( V_18 , V_19 , & V_6 -> V_11 . V_12 ) ;
}
static int F_15 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_16 ( V_21 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_22 V_23 ;
unsigned int V_24 ;
int V_16 ;
for ( V_16 = F_17 ( & V_23 , V_21 , false ) ;
( V_24 = V_23 . V_24 ) ; V_16 = F_18 ( & V_23 , V_24 ) ) {
T_2 V_25 = V_24 / V_26 ;
T_1 * V_19 = V_23 . V_19 . V_27 . V_28 ;
T_1 * V_18 = V_23 . V_18 . V_27 . V_28 ;
T_1 * V_29 = V_23 . V_29 ;
if ( V_25 >= 8 ) {
F_19 () ;
F_20 ( V_18 , V_19 , V_24 , & V_6 -> V_11 , V_29 ) ;
F_21 () ;
V_24 %= V_26 ;
continue;
}
V_24 = F_22 ( & V_23 , V_2 ,
F_13 ) ;
}
return V_16 ;
}
static void F_23 ( T_3 V_30 [] , T_2 V_31 )
{
int V_32 ;
for ( V_32 = 3 ; V_32 >= 0 ; V_32 -- , V_31 = 1 ) {
T_2 V_33 = F_24 ( V_30 [ V_32 ] ) + V_31 ;
V_30 [ V_32 ] = F_25 ( V_33 ) ;
if ( V_33 >= V_31 )
break;
}
}
static int F_26 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_16 ( V_21 ) ;
struct V_14 * V_6 = F_2 ( V_2 ) ;
struct V_22 V_23 ;
T_2 V_25 ;
int V_16 ;
V_16 = F_17 ( & V_23 , V_21 , false ) ;
while ( ( V_25 = V_23 . V_24 / V_26 ) ) {
T_2 V_34 = V_23 . V_24 % V_26 ;
T_3 * V_30 = ( T_3 * ) V_23 . V_29 ;
T_2 V_35 = V_36 - F_24 ( V_30 [ 3 ] ) ;
if ( F_27 ( V_35 < V_25 ) ) {
V_25 = V_35 + 1 ;
V_34 = V_23 . V_24 - V_25 * V_26 ;
}
F_19 () ;
F_28 ( V_23 . V_18 . V_27 . V_28 ,
V_23 . V_19 . V_27 . V_28 , V_25 ,
& V_6 -> V_8 , V_23 . V_29 ) ;
F_21 () ;
F_23 ( V_30 , V_25 ) ;
V_16 = F_18 ( & V_23 , V_34 ) ;
}
if ( V_23 . V_24 ) {
T_1 * V_37 = V_23 . V_19 . V_27 . V_28 + V_25 * V_26 ;
T_1 * V_38 = V_23 . V_18 . V_27 . V_28 + V_25 * V_26 ;
T_1 V_39 [ V_26 ] ;
F_10 ( V_23 . V_29 , V_39 , & V_6 -> V_8 . V_12 ) ;
if ( V_37 != V_38 )
memcpy ( V_37 , V_38 , V_23 . V_24 ) ;
F_29 ( V_37 , V_39 , V_23 . V_24 ) ;
V_16 = F_18 ( & V_23 , 0 ) ;
}
return V_16 ;
}
static int F_30 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_16 ( V_21 ) ;
struct V_15 * V_6 = F_2 ( V_2 ) ;
struct V_22 V_23 ;
int V_16 ;
V_16 = F_17 ( & V_23 , V_21 , false ) ;
F_10 ( V_23 . V_29 , V_23 . V_29 , & V_6 -> V_17 ) ;
while ( V_23 . V_24 ) {
F_19 () ;
F_31 ( V_23 . V_18 . V_27 . V_28 , V_23 . V_19 . V_27 . V_28 ,
V_23 . V_24 , & V_6 -> V_8 , V_23 . V_29 ) ;
F_21 () ;
V_16 = F_18 ( & V_23 , V_23 . V_24 % V_26 ) ;
}
return V_16 ;
}
static int F_32 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_16 ( V_21 ) ;
struct V_15 * V_6 = F_2 ( V_2 ) ;
struct V_22 V_23 ;
int V_16 ;
V_16 = F_17 ( & V_23 , V_21 , false ) ;
F_10 ( V_23 . V_29 , V_23 . V_29 , & V_6 -> V_17 ) ;
while ( V_23 . V_24 ) {
F_19 () ;
F_33 ( V_23 . V_18 . V_27 . V_28 , V_23 . V_19 . V_27 . V_28 ,
V_23 . V_24 , & V_6 -> V_11 , V_23 . V_29 ) ;
F_21 () ;
V_16 = F_18 ( & V_23 , V_23 . V_24 % V_26 ) ;
}
return V_16 ;
}
static void F_34 ( void )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < F_35 ( V_40 ) && V_40 [ V_32 ] ; V_32 ++ )
F_36 ( V_40 [ V_32 ] ) ;
F_37 ( V_41 , F_35 ( V_41 ) ) ;
}
static int T_4 F_38 ( void )
{
struct V_42 * V_43 ;
const char * V_44 ;
const char * V_45 ;
const char * V_46 ;
int V_16 ;
int V_32 ;
if ( ! F_39 () )
return - V_47 ;
V_16 = F_40 ( V_41 , F_35 ( V_41 ) ) ;
if ( V_16 )
return V_16 ;
for ( V_32 = 0 ; V_32 < F_35 ( V_41 ) ; V_32 ++ ) {
V_45 = V_41 [ V_32 ] . V_48 . V_49 + 2 ;
V_46 = V_41 [ V_32 ] . V_48 . V_50 + 2 ;
V_44 = V_41 [ V_32 ] . V_48 . V_50 ;
V_43 = F_41 ( V_45 , V_46 , V_44 ) ;
V_16 = F_42 ( V_43 ) ;
if ( F_43 ( V_43 ) )
goto V_51;
V_40 [ V_32 ] = V_43 ;
}
return 0 ;
V_51:
F_34 () ;
return V_16 ;
}
