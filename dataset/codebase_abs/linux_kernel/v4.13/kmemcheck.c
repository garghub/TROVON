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
int V_6 ;
int V_7 ;
if ( ! V_5 )
return - V_4 ;
V_7 = F_6 ( V_5 , 0 , & V_6 ) ;
if ( V_7 )
return V_7 ;
V_3 = V_6 ;
return 0 ;
}
int F_7 ( unsigned long V_8 )
{
T_2 * V_9 ;
V_9 = F_8 ( V_8 ) ;
if ( ! V_9 )
return 0 ;
F_9 ( V_9 , F_10 ( F_11 ( * V_9 ) | V_10 ) ) ;
F_12 ( V_8 ) ;
return 1 ;
}
int F_13 ( unsigned long V_8 )
{
T_2 * V_9 ;
V_9 = F_8 ( V_8 ) ;
if ( ! V_9 )
return 0 ;
F_9 ( V_9 , F_10 ( F_11 ( * V_9 ) & ~ V_10 ) ) ;
F_12 ( V_8 ) ;
return 1 ;
}
bool F_14 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_15 ( & V_13 ) ;
return V_14 -> V_15 > 0 ;
}
static void F_16 ( unsigned long V_16 )
{
struct V_13 * V_14 = F_15 ( & V_13 ) ;
F_17 ( V_14 -> V_17 >= F_18 ( V_14 -> V_16 ) ) ;
V_14 -> V_16 [ V_14 -> V_17 ++ ] = V_16 ;
}
static unsigned int F_19 ( void )
{
struct V_13 * V_14 = F_15 ( & V_13 ) ;
unsigned int V_18 ;
unsigned int V_19 ;
V_19 = 0 ;
for ( V_18 = 0 ; V_18 < V_14 -> V_17 ; ++ V_18 )
V_19 += F_7 ( V_14 -> V_16 [ V_18 ] ) ;
return V_19 ;
}
static unsigned int F_20 ( void )
{
struct V_13 * V_14 = F_15 ( & V_13 ) ;
unsigned int V_18 ;
unsigned int V_19 ;
V_19 = 0 ;
for ( V_18 = 0 ; V_18 < V_14 -> V_17 ; ++ V_18 )
V_19 += F_13 ( V_14 -> V_16 [ V_18 ] ) ;
return V_19 ;
}
void F_21 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_15 ( & V_13 ) ;
F_17 ( ! F_22 () ) ;
if ( F_23 ( V_14 -> V_15 != 0 ) ) {
F_19 () ;
F_24 ( V_12 ) ;
V_14 -> V_15 = 0 ;
return;
}
if ( F_19 () == 0 )
return;
++ V_14 -> V_15 ;
if ( ! ( V_12 -> V_20 & V_21 ) )
V_14 -> V_20 = V_12 -> V_20 ;
V_12 -> V_20 |= V_21 ;
V_12 -> V_20 &= ~ V_22 ;
}
void F_25 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_15 ( & V_13 ) ;
int V_19 ;
F_17 ( ! F_22 () ) ;
if ( F_23 ( V_14 -> V_15 != 1 ) ) {
F_19 () ;
F_24 ( V_12 ) ;
V_14 -> V_17 = 0 ;
V_14 -> V_15 = 0 ;
if ( ! ( V_14 -> V_20 & V_21 ) )
V_12 -> V_20 &= ~ V_21 ;
if ( V_14 -> V_20 & V_22 )
V_12 -> V_20 |= V_22 ;
return;
}
if ( V_3 )
V_19 = F_20 () ;
else
V_19 = F_19 () ;
if ( V_19 == 0 )
return;
-- V_14 -> V_15 ;
V_14 -> V_17 = 0 ;
if ( ! ( V_14 -> V_20 & V_21 ) )
V_12 -> V_20 &= ~ V_21 ;
if ( V_14 -> V_20 & V_22 )
V_12 -> V_20 |= V_22 ;
}
void F_26 ( struct V_23 * V_24 , unsigned int V_19 )
{
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; ++ V_18 ) {
unsigned long V_8 ;
T_2 * V_9 ;
unsigned int V_25 ;
V_8 = ( unsigned long ) F_27 ( & V_24 [ V_18 ] ) ;
V_9 = F_28 ( V_8 , & V_25 ) ;
F_17 ( ! V_9 ) ;
F_17 ( V_25 != V_26 ) ;
F_9 ( V_9 , F_10 ( F_11 ( * V_9 ) | V_10 ) ) ;
F_9 ( V_9 , F_10 ( F_11 ( * V_9 ) & ~ V_27 ) ) ;
F_12 ( V_8 ) ;
}
}
bool F_29 ( struct V_23 * V_24 )
{
return F_8 ( ( unsigned long ) F_27 ( V_24 ) ) ;
}
void F_30 ( struct V_23 * V_24 , unsigned int V_19 )
{
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; ++ V_18 ) {
unsigned long V_8 ;
T_2 * V_9 ;
unsigned int V_25 ;
V_8 = ( unsigned long ) F_27 ( & V_24 [ V_18 ] ) ;
V_9 = F_28 ( V_8 , & V_25 ) ;
F_17 ( ! V_9 ) ;
F_17 ( V_25 != V_26 ) ;
F_9 ( V_9 , F_10 ( F_11 ( * V_9 ) & ~ V_10 ) ) ;
F_9 ( V_9 , F_10 ( F_11 ( * V_9 ) | V_27 ) ) ;
F_12 ( V_8 ) ;
}
}
static void F_31 ( struct V_11 * V_12 ,
unsigned long V_16 , unsigned int V_28 )
{
void * V_29 ;
enum V_30 V_31 ;
V_29 = F_32 ( V_16 ) ;
if ( ! V_29 )
return;
F_16 ( V_16 ) ;
V_31 = F_33 ( V_29 , V_28 ) ;
if ( V_31 == V_32 )
return;
if ( V_3 )
F_34 ( V_31 , V_16 , V_28 , V_12 ) ;
if ( V_3 == 2 )
V_3 = 0 ;
F_35 ( V_29 , V_28 ) ;
}
bool F_36 ( unsigned long V_16 , T_3 V_28 )
{
enum V_30 V_31 ;
void * V_29 ;
V_29 = F_32 ( V_16 ) ;
if ( ! V_29 )
return true ;
V_31 = F_37 ( V_29 , V_28 ) ;
return V_31 == V_32 ;
}
static void F_38 ( struct V_11 * V_12 ,
unsigned long V_16 , unsigned int V_28 )
{
unsigned long V_23 = V_16 & V_33 ;
unsigned long V_34 = V_16 + V_28 - 1 ;
unsigned long V_35 = V_34 & V_33 ;
if ( F_39 ( V_23 == V_35 ) ) {
F_31 ( V_12 , V_16 , V_28 ) ;
return;
}
F_31 ( V_12 , V_16 , V_35 - V_16 ) ;
F_31 ( V_12 , V_35 , V_34 - V_35 ) ;
}
static void F_40 ( struct V_11 * V_12 ,
unsigned long V_16 , unsigned int V_28 )
{
void * V_29 ;
V_29 = F_32 ( V_16 ) ;
if ( ! V_29 )
return;
F_16 ( V_16 ) ;
F_35 ( V_29 , V_28 ) ;
}
static void F_41 ( struct V_11 * V_12 ,
unsigned long V_16 , unsigned int V_28 )
{
unsigned long V_23 = V_16 & V_33 ;
unsigned long V_34 = V_16 + V_28 - 1 ;
unsigned long V_35 = V_34 & V_33 ;
if ( F_39 ( V_23 == V_35 ) ) {
F_40 ( V_12 , V_16 , V_28 ) ;
return;
}
F_40 ( V_12 , V_16 , V_35 - V_16 ) ;
F_40 ( V_12 , V_35 , V_34 - V_35 ) ;
}
static void F_42 ( struct V_11 * V_12 ,
unsigned long V_36 , unsigned long V_37 , unsigned int V_28 )
{
T_4 V_29 [ 8 ] ;
enum V_30 V_31 ;
unsigned long V_23 ;
unsigned long V_34 ;
unsigned long V_35 ;
T_4 * V_38 ;
unsigned int V_18 ;
unsigned int V_19 ;
F_17 ( V_28 > sizeof( V_29 ) ) ;
V_23 = V_36 & V_33 ;
V_34 = V_36 + V_28 - 1 ;
V_35 = V_34 & V_33 ;
if ( F_39 ( V_23 == V_35 ) ) {
V_38 = F_32 ( V_36 ) ;
if ( V_38 ) {
F_16 ( V_36 ) ;
for ( V_18 = 0 ; V_18 < V_28 ; ++ V_18 )
V_29 [ V_18 ] = V_38 [ V_18 ] ;
} else {
for ( V_18 = 0 ; V_18 < V_28 ; ++ V_18 )
V_29 [ V_18 ] = V_32 ;
}
} else {
V_19 = V_35 - V_36 ;
F_17 ( V_19 > sizeof( V_29 ) ) ;
V_38 = F_32 ( V_36 ) ;
if ( V_38 ) {
F_16 ( V_36 ) ;
for ( V_18 = 0 ; V_18 < V_19 ; ++ V_18 )
V_29 [ V_18 ] = V_38 [ V_18 ] ;
} else {
for ( V_18 = 0 ; V_18 < V_19 ; ++ V_18 )
V_29 [ V_18 ] = V_32 ;
}
V_38 = F_32 ( V_35 ) ;
if ( V_38 ) {
F_16 ( V_35 ) ;
for ( V_18 = V_19 ; V_18 < V_28 ; ++ V_18 )
V_29 [ V_18 ] = V_38 [ V_18 - V_19 ] ;
} else {
for ( V_18 = V_19 ; V_18 < V_28 ; ++ V_18 )
V_29 [ V_18 ] = V_32 ;
}
}
V_23 = V_37 & V_33 ;
V_34 = V_37 + V_28 - 1 ;
V_35 = V_34 & V_33 ;
if ( F_39 ( V_23 == V_35 ) ) {
V_38 = F_32 ( V_37 ) ;
if ( V_38 ) {
F_16 ( V_37 ) ;
for ( V_18 = 0 ; V_18 < V_28 ; ++ V_18 ) {
V_38 [ V_18 ] = V_29 [ V_18 ] ;
V_29 [ V_18 ] = V_32 ;
}
}
} else {
V_19 = V_35 - V_37 ;
F_17 ( V_19 > sizeof( V_29 ) ) ;
V_38 = F_32 ( V_37 ) ;
if ( V_38 ) {
F_16 ( V_37 ) ;
for ( V_18 = 0 ; V_18 < V_19 ; ++ V_18 ) {
V_38 [ V_18 ] = V_29 [ V_18 ] ;
V_29 [ V_18 ] = V_32 ;
}
}
V_38 = F_32 ( V_35 ) ;
if ( V_38 ) {
F_16 ( V_35 ) ;
for ( V_18 = V_19 ; V_18 < V_28 ; ++ V_18 ) {
V_38 [ V_18 - V_19 ] = V_29 [ V_18 ] ;
V_29 [ V_18 ] = V_32 ;
}
}
}
V_31 = F_33 ( V_29 , V_28 ) ;
if ( V_31 == V_32 )
return;
if ( V_3 )
F_34 ( V_31 , V_36 , V_28 , V_12 ) ;
if ( V_3 == 2 )
V_3 = 0 ;
}
static void F_43 ( struct V_11 * V_12 ,
unsigned long V_39 , enum V_40 V_41 )
{
const T_4 * V_42 ;
const T_4 * V_43 ;
unsigned int V_28 ;
struct V_13 * V_14 = F_15 ( & V_13 ) ;
if ( V_14 -> V_44 ) {
F_7 ( V_39 ) ;
F_24 ( V_12 ) ;
return;
}
V_14 -> V_44 = true ;
V_42 = ( const T_4 * ) V_12 -> V_45 ;
V_43 = F_44 ( V_42 ) ;
F_45 ( V_42 , & V_28 ) ;
switch ( V_43 [ 0 ] ) {
#ifdef F_46
case 0x80 :
case 0x81 :
case 0x82 :
case 0x83 :
switch ( ( V_43 [ 1 ] >> 3 ) & 7 ) {
case 1 :
case 4 :
case 6 :
F_41 ( V_12 , V_39 , V_28 ) ;
goto V_46;
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
F_42 ( V_12 , V_12 -> V_47 , V_12 -> V_48 , V_28 ) ;
goto V_46;
case 0xa6 :
case 0xa7 :
F_38 ( V_12 , V_12 -> V_47 , V_28 ) ;
F_38 ( V_12 , V_12 -> V_48 , V_28 ) ;
goto V_46;
}
switch ( V_41 ) {
case V_49 :
F_38 ( V_12 , V_39 , V_28 ) ;
goto V_46;
case V_50 :
F_41 ( V_12 , V_39 , V_28 ) ;
goto V_46;
}
V_46:
V_14 -> V_44 = false ;
}
bool F_47 ( struct V_11 * V_12 , unsigned long V_8 ,
unsigned long V_51 )
{
T_2 * V_9 ;
if ( V_12 -> V_20 & V_52 )
return false ;
if ( V_12 -> V_53 != V_54 )
return false ;
V_9 = F_8 ( V_8 ) ;
if ( ! V_9 )
return false ;
F_48 ( F_49 () ) ;
if ( V_51 & 2 )
F_43 ( V_12 , V_8 , V_50 ) ;
else
F_43 ( V_12 , V_8 , V_49 ) ;
F_21 ( V_12 ) ;
return true ;
}
bool F_50 ( struct V_11 * V_12 )
{
if ( ! F_14 ( V_12 ) )
return false ;
F_25 ( V_12 ) ;
return true ;
}
