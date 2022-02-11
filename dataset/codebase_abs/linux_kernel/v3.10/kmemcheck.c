int T_1 F_1 ( void )
{
#ifdef F_2
if ( V_1 > 1 ) {
F_3 ( V_2
L_1 ) ;
V_1 = 1 ;
}
#endif
if ( ! F_4 () ) {
F_3 ( V_2 L_2 ) ;
V_3 = 0 ;
return - V_4 ;
}
F_3 ( V_2 L_3 ) ;
return 0 ;
}
static int T_1 F_5 ( char * V_5 )
{
if ( ! V_5 )
return - V_4 ;
sscanf ( V_5 , L_4 , & V_3 ) ;
return 0 ;
}
int F_6 ( unsigned long V_6 )
{
T_2 * V_7 ;
V_7 = F_7 ( V_6 ) ;
if ( ! V_7 )
return 0 ;
F_8 ( V_7 , F_9 ( F_10 ( * V_7 ) | V_8 ) ) ;
F_11 ( V_6 ) ;
return 1 ;
}
int F_12 ( unsigned long V_6 )
{
T_2 * V_7 ;
V_7 = F_7 ( V_6 ) ;
if ( ! V_7 )
return 0 ;
F_8 ( V_7 , F_9 ( F_10 ( * V_7 ) & ~ V_8 ) ) ;
F_11 ( V_6 ) ;
return 1 ;
}
bool F_13 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = & F_14 ( V_11 ) ;
return V_12 -> V_13 > 0 ;
}
static void F_15 ( unsigned long V_14 )
{
struct V_11 * V_12 = & F_14 ( V_11 ) ;
F_16 ( V_12 -> V_15 >= F_17 ( V_12 -> V_14 ) ) ;
V_12 -> V_14 [ V_12 -> V_15 ++ ] = V_14 ;
}
static unsigned int F_18 ( void )
{
struct V_11 * V_12 = & F_14 ( V_11 ) ;
unsigned int V_16 ;
unsigned int V_17 ;
V_17 = 0 ;
for ( V_16 = 0 ; V_16 < V_12 -> V_15 ; ++ V_16 )
V_17 += F_6 ( V_12 -> V_14 [ V_16 ] ) ;
return V_17 ;
}
static unsigned int F_19 ( void )
{
struct V_11 * V_12 = & F_14 ( V_11 ) ;
unsigned int V_16 ;
unsigned int V_17 ;
V_17 = 0 ;
for ( V_16 = 0 ; V_16 < V_12 -> V_15 ; ++ V_16 )
V_17 += F_12 ( V_12 -> V_14 [ V_16 ] ) ;
return V_17 ;
}
void F_20 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = & F_14 ( V_11 ) ;
F_16 ( ! F_21 () ) ;
if ( F_22 ( V_12 -> V_13 != 0 ) ) {
F_18 () ;
F_23 ( V_10 ) ;
V_12 -> V_13 = 0 ;
return;
}
if ( F_18 () == 0 )
return;
++ V_12 -> V_13 ;
if ( ! ( V_10 -> V_18 & V_19 ) )
V_12 -> V_18 = V_10 -> V_18 ;
V_10 -> V_18 |= V_19 ;
V_10 -> V_18 &= ~ V_20 ;
}
void F_24 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = & F_14 ( V_11 ) ;
int V_17 ;
F_16 ( ! F_21 () ) ;
if ( F_22 ( V_12 -> V_13 != 1 ) ) {
F_18 () ;
F_23 ( V_10 ) ;
V_12 -> V_15 = 0 ;
V_12 -> V_13 = 0 ;
if ( ! ( V_12 -> V_18 & V_19 ) )
V_10 -> V_18 &= ~ V_19 ;
if ( V_12 -> V_18 & V_20 )
V_10 -> V_18 |= V_20 ;
return;
}
if ( V_3 )
V_17 = F_19 () ;
else
V_17 = F_18 () ;
if ( V_17 == 0 )
return;
-- V_12 -> V_13 ;
V_12 -> V_15 = 0 ;
if ( ! ( V_12 -> V_18 & V_19 ) )
V_10 -> V_18 &= ~ V_19 ;
if ( V_12 -> V_18 & V_20 )
V_10 -> V_18 |= V_20 ;
}
void F_25 ( struct V_21 * V_22 , unsigned int V_17 )
{
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; ++ V_16 ) {
unsigned long V_6 ;
T_2 * V_7 ;
unsigned int V_23 ;
V_6 = ( unsigned long ) F_26 ( & V_22 [ V_16 ] ) ;
V_7 = F_27 ( V_6 , & V_23 ) ;
F_16 ( ! V_7 ) ;
F_16 ( V_23 != V_24 ) ;
F_8 ( V_7 , F_9 ( F_10 ( * V_7 ) | V_8 ) ) ;
F_8 ( V_7 , F_9 ( F_10 ( * V_7 ) & ~ V_25 ) ) ;
F_11 ( V_6 ) ;
}
}
bool F_28 ( struct V_21 * V_22 )
{
return F_7 ( ( unsigned long ) F_26 ( V_22 ) ) ;
}
void F_29 ( struct V_21 * V_22 , unsigned int V_17 )
{
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; ++ V_16 ) {
unsigned long V_6 ;
T_2 * V_7 ;
unsigned int V_23 ;
V_6 = ( unsigned long ) F_26 ( & V_22 [ V_16 ] ) ;
V_7 = F_27 ( V_6 , & V_23 ) ;
F_16 ( ! V_7 ) ;
F_16 ( V_23 != V_24 ) ;
F_8 ( V_7 , F_9 ( F_10 ( * V_7 ) & ~ V_8 ) ) ;
F_8 ( V_7 , F_9 ( F_10 ( * V_7 ) | V_25 ) ) ;
F_11 ( V_6 ) ;
}
}
static void F_30 ( struct V_9 * V_10 ,
unsigned long V_14 , unsigned int V_26 )
{
void * V_27 ;
enum V_28 V_29 ;
V_27 = F_31 ( V_14 ) ;
if ( ! V_27 )
return;
F_15 ( V_14 ) ;
V_29 = F_32 ( V_27 , V_26 ) ;
if ( V_29 == V_30 )
return;
if ( V_3 )
F_33 ( V_29 , V_14 , V_26 , V_10 ) ;
if ( V_3 == 2 )
V_3 = 0 ;
F_34 ( V_27 , V_26 ) ;
}
bool F_35 ( unsigned long V_14 , T_3 V_26 )
{
enum V_28 V_29 ;
void * V_27 ;
V_27 = F_31 ( V_14 ) ;
if ( ! V_27 )
return true ;
V_29 = F_36 ( V_27 , V_26 ) ;
return V_29 == V_30 ;
}
static void F_37 ( struct V_9 * V_10 ,
unsigned long V_14 , unsigned int V_26 )
{
unsigned long V_21 = V_14 & V_31 ;
unsigned long V_32 = V_14 + V_26 - 1 ;
unsigned long V_33 = V_32 & V_31 ;
if ( F_38 ( V_21 == V_33 ) ) {
F_30 ( V_10 , V_14 , V_26 ) ;
return;
}
F_30 ( V_10 , V_14 , V_33 - V_14 ) ;
F_30 ( V_10 , V_33 , V_32 - V_33 ) ;
}
static void F_39 ( struct V_9 * V_10 ,
unsigned long V_14 , unsigned int V_26 )
{
void * V_27 ;
V_27 = F_31 ( V_14 ) ;
if ( ! V_27 )
return;
F_15 ( V_14 ) ;
F_34 ( V_27 , V_26 ) ;
}
static void F_40 ( struct V_9 * V_10 ,
unsigned long V_14 , unsigned int V_26 )
{
unsigned long V_21 = V_14 & V_31 ;
unsigned long V_32 = V_14 + V_26 - 1 ;
unsigned long V_33 = V_32 & V_31 ;
if ( F_38 ( V_21 == V_33 ) ) {
F_39 ( V_10 , V_14 , V_26 ) ;
return;
}
F_39 ( V_10 , V_14 , V_33 - V_14 ) ;
F_39 ( V_10 , V_33 , V_32 - V_33 ) ;
}
static void F_41 ( struct V_9 * V_10 ,
unsigned long V_34 , unsigned long V_35 , unsigned int V_26 )
{
T_4 V_27 [ 8 ] ;
enum V_28 V_29 ;
unsigned long V_21 ;
unsigned long V_32 ;
unsigned long V_33 ;
T_4 * V_36 ;
unsigned int V_16 ;
unsigned int V_17 ;
F_16 ( V_26 > sizeof( V_27 ) ) ;
V_21 = V_34 & V_31 ;
V_32 = V_34 + V_26 - 1 ;
V_33 = V_32 & V_31 ;
if ( F_38 ( V_21 == V_33 ) ) {
V_36 = F_31 ( V_34 ) ;
if ( V_36 ) {
F_15 ( V_34 ) ;
for ( V_16 = 0 ; V_16 < V_26 ; ++ V_16 )
V_27 [ V_16 ] = V_36 [ V_16 ] ;
} else {
for ( V_16 = 0 ; V_16 < V_26 ; ++ V_16 )
V_27 [ V_16 ] = V_30 ;
}
} else {
V_17 = V_33 - V_34 ;
F_16 ( V_17 > sizeof( V_27 ) ) ;
V_36 = F_31 ( V_34 ) ;
if ( V_36 ) {
F_15 ( V_34 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; ++ V_16 )
V_27 [ V_16 ] = V_36 [ V_16 ] ;
} else {
for ( V_16 = 0 ; V_16 < V_17 ; ++ V_16 )
V_27 [ V_16 ] = V_30 ;
}
V_36 = F_31 ( V_33 ) ;
if ( V_36 ) {
F_15 ( V_33 ) ;
for ( V_16 = V_17 ; V_16 < V_26 ; ++ V_16 )
V_27 [ V_16 ] = V_36 [ V_16 - V_17 ] ;
} else {
for ( V_16 = V_17 ; V_16 < V_26 ; ++ V_16 )
V_27 [ V_16 ] = V_30 ;
}
}
V_21 = V_35 & V_31 ;
V_32 = V_35 + V_26 - 1 ;
V_33 = V_32 & V_31 ;
if ( F_38 ( V_21 == V_33 ) ) {
V_36 = F_31 ( V_35 ) ;
if ( V_36 ) {
F_15 ( V_35 ) ;
for ( V_16 = 0 ; V_16 < V_26 ; ++ V_16 ) {
V_36 [ V_16 ] = V_27 [ V_16 ] ;
V_27 [ V_16 ] = V_30 ;
}
}
} else {
V_17 = V_33 - V_35 ;
F_16 ( V_17 > sizeof( V_27 ) ) ;
V_36 = F_31 ( V_35 ) ;
if ( V_36 ) {
F_15 ( V_35 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; ++ V_16 ) {
V_36 [ V_16 ] = V_27 [ V_16 ] ;
V_27 [ V_16 ] = V_30 ;
}
}
V_36 = F_31 ( V_33 ) ;
if ( V_36 ) {
F_15 ( V_33 ) ;
for ( V_16 = V_17 ; V_16 < V_26 ; ++ V_16 ) {
V_36 [ V_16 - V_17 ] = V_27 [ V_16 ] ;
V_27 [ V_16 ] = V_30 ;
}
}
}
V_29 = F_32 ( V_27 , V_26 ) ;
if ( V_29 == V_30 )
return;
if ( V_3 )
F_33 ( V_29 , V_34 , V_26 , V_10 ) ;
if ( V_3 == 2 )
V_3 = 0 ;
}
static void F_42 ( struct V_9 * V_10 ,
unsigned long V_37 , enum V_38 V_39 )
{
const T_4 * V_40 ;
const T_4 * V_41 ;
unsigned int V_26 ;
struct V_11 * V_12 = & F_14 ( V_11 ) ;
if ( V_12 -> V_42 ) {
F_6 ( V_37 ) ;
F_23 ( V_10 ) ;
return;
}
V_12 -> V_42 = true ;
V_40 = ( const T_4 * ) V_10 -> V_43 ;
V_41 = F_43 ( V_40 ) ;
F_44 ( V_40 , & V_26 ) ;
switch ( V_41 [ 0 ] ) {
#ifdef F_45
case 0x80 :
case 0x81 :
case 0x82 :
case 0x83 :
switch ( ( V_41 [ 1 ] >> 3 ) & 7 ) {
case 1 :
case 4 :
case 6 :
F_40 ( V_10 , V_37 , V_26 ) ;
goto V_44;
case 0 :
case 2 :
case 3 :
case 5 :
case 7 :
break;
}
break;
#endif
case 0xa4 :
case 0xa5 :
F_41 ( V_10 , V_10 -> V_45 , V_10 -> V_46 , V_26 ) ;
goto V_44;
case 0xa6 :
case 0xa7 :
F_37 ( V_10 , V_10 -> V_45 , V_26 ) ;
F_37 ( V_10 , V_10 -> V_46 , V_26 ) ;
goto V_44;
}
switch ( V_39 ) {
case V_47 :
F_37 ( V_10 , V_37 , V_26 ) ;
goto V_44;
case V_48 :
F_40 ( V_10 , V_37 , V_26 ) ;
goto V_44;
}
V_44:
V_12 -> V_42 = false ;
}
bool F_46 ( struct V_9 * V_10 , unsigned long V_6 ,
unsigned long V_49 )
{
T_2 * V_7 ;
if ( V_10 -> V_18 & V_50 )
return false ;
if ( V_10 -> V_51 != V_52 )
return false ;
V_7 = F_7 ( V_6 ) ;
if ( ! V_7 )
return false ;
F_47 ( F_48 () ) ;
if ( V_49 & 2 )
F_42 ( V_10 , V_6 , V_48 ) ;
else
F_42 ( V_10 , V_6 , V_47 ) ;
F_20 ( V_10 ) ;
return true ;
}
bool F_49 ( struct V_9 * V_10 )
{
if ( ! F_13 ( V_10 ) )
return false ;
F_24 ( V_10 ) ;
return true ;
}
