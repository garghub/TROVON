static T_1 F_1 ( struct V_1 * V_1 , unsigned long V_2 )
{
return F_2 ( V_1 -> V_3 + V_2 ) ;
}
static void F_3 ( struct V_1 * V_1 , T_1 V_4 , unsigned long V_2 )
{
F_4 ( V_4 , V_1 -> V_3 + V_2 ) ;
}
static struct V_5 * F_5 ( unsigned int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ )
if ( V_9 [ V_7 ] . V_10 == V_6 )
return V_9 + V_7 ;
return NULL ;
}
static void F_6 ( struct V_11 * V_12 )
{
struct V_5 * V_13 = F_7 ( V_12 ) ;
struct V_14 * V_15 ;
T_2 V_2 ;
unsigned long V_16 ;
F_8 ( & V_17 , V_16 ) ;
V_15 = V_13 -> V_15 ;
if ( ! V_15 ) {
F_9 ( & V_17 , V_16 ) ;
F_10 ( L_1 , V_18 , V_12 -> V_19 ) ;
return;
}
V_2 = F_1 ( V_15 -> V_1 , V_15 -> V_20 ) ;
V_2 |= ( 1UL << ( V_13 -> V_10 & 31 ) ) ;
F_3 ( V_15 -> V_1 , V_2 , V_15 -> V_20 ) ;
F_9 ( & V_17 , V_16 ) ;
}
static void F_11 ( struct V_11 * V_12 )
{
struct V_5 * V_13 = F_7 ( V_12 ) ;
struct V_14 * V_15 ;
T_2 V_2 ;
unsigned long V_16 ;
F_8 ( & V_17 , V_16 ) ;
V_15 = V_13 -> V_15 ;
if ( ! V_15 ) {
F_9 ( & V_17 , V_16 ) ;
F_10 ( L_1 , V_18 , V_12 -> V_19 ) ;
return;
}
V_2 = F_1 ( V_15 -> V_1 , V_15 -> V_20 ) ;
V_2 &= ~ ( 1UL << ( V_13 -> V_10 & 31 ) ) ;
F_3 ( V_15 -> V_1 , V_2 , V_15 -> V_20 ) ;
F_9 ( & V_17 , V_16 ) ;
}
static void F_12 ( struct V_11 * V_12 )
{
struct V_5 * V_13 = F_7 ( V_12 ) ;
struct V_14 * V_15 ;
unsigned long V_16 ;
F_8 ( & V_17 , V_16 ) ;
V_15 = V_13 -> V_15 ;
if ( ! V_15 ) {
F_9 ( & V_17 , V_16 ) ;
F_10 ( L_1 , V_18 , V_12 -> V_19 ) ;
return;
}
F_3 ( V_15 -> V_1 , 1UL << ( V_13 -> V_10 & 31 ) , V_15 -> V_21 ) ;
F_9 ( & V_17 , V_16 ) ;
}
bool F_13 ( unsigned int V_19 )
{
struct V_5 * V_13 = F_14 ( V_19 ) ;
struct V_14 * V_15 ;
unsigned long V_16 ;
bool V_22 ;
F_8 ( & V_17 , V_16 ) ;
V_15 = V_13 -> V_15 ;
V_22 = V_15 && F_1 ( V_15 -> V_1 , V_15 -> V_21 ) &
( 1UL << ( V_13 -> V_10 & 31 ) ) ;
F_9 ( & V_17 , V_16 ) ;
return V_22 ;
}
int V_5 ( unsigned int V_10 )
{
int V_7 , V_22 = - V_23 ;
struct V_5 * V_13 ;
F_15 () ;
F_16 ( & V_24 ) ;
V_13 = F_5 ( V_10 ) ;
if ( V_13 ) {
F_10 ( L_2 , V_10 , V_13 -> V_19 ) ;
V_22 = - V_25 ;
goto V_26;
}
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
if ( V_9 [ V_7 ] . V_10 < 0 ) {
unsigned long V_16 ;
F_8 ( & V_17 , V_16 ) ;
V_9 [ V_7 ] . V_10 = V_10 ;
V_9 [ V_7 ] . V_15 = V_27 + V_10 / 32 ;
F_9 ( & V_17 , V_16 ) ;
V_22 = V_9 [ V_7 ] . V_19 ;
F_17 ( L_3 ,
V_10 , V_22 ) ;
break;
}
}
V_26:
F_18 ( & V_24 ) ;
if ( V_22 < 0 )
F_10 ( L_4 , V_10 , V_22 ) ;
return V_22 ;
}
int F_19 ( unsigned int V_10 )
{
int V_7 , V_22 = - V_28 ;
F_15 () ;
F_16 ( & V_24 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
if ( V_9 [ V_7 ] . V_10 == V_10 ) {
unsigned long V_16 ;
F_17 ( L_5 ,
V_10 , V_9 [ V_7 ] . V_19 ) ;
F_8 ( & V_17 , V_16 ) ;
V_9 [ V_7 ] . V_10 = - V_28 ;
V_9 [ V_7 ] . V_15 = NULL ;
F_9 ( & V_17 , V_16 ) ;
V_22 = 0 ;
break;
}
}
F_18 ( & V_24 ) ;
return V_22 ;
}
static void F_20 ( unsigned int V_19 , struct V_29 * V_30 )
{
struct V_1 * V_1 = F_21 ( V_19 ) ;
T_1 V_21 ;
int V_7 , line ;
for ( V_7 = V_31 ; V_7 < V_32 ; V_7 ++ ) {
struct V_14 * V_15 = V_27 + V_7 ;
F_22 ( & V_17 ) ;
V_21 = F_1 ( V_1 , V_15 -> V_21 ) ;
V_21 &= F_1 ( V_1 , V_15 -> V_20 ) ;
F_23 ( & V_17 ) ;
while ( ( line = F_24 ( V_21 ) ) ) {
struct V_5 * V_13 ;
line -- ;
V_21 &= ~ ( 1UL << line ) ;
F_22 ( & V_17 ) ;
V_13 = F_5 ( 32 * V_7 + line ) ;
if ( V_13 )
V_19 = V_13 -> V_19 ;
F_23 ( & V_17 ) ;
if ( ! V_13 ) {
F_10 ( L_6 ,
line , V_7 ) ;
continue;
}
F_25 ( V_19 ) ;
}
}
}
static void F_26 ( unsigned int V_19 , struct V_29 * V_30 )
{
struct V_1 * V_1 = F_27 ( V_30 ) ;
T_1 V_21 ;
int V_7 , line ;
for ( V_7 = 0 ; V_7 < V_31 ; V_7 ++ ) {
struct V_14 * V_15 = V_27 + V_7 ;
F_22 ( & V_17 ) ;
V_21 = F_1 ( V_1 , V_15 -> V_21 ) ;
V_21 &= F_1 ( V_1 , V_15 -> V_20 ) ;
F_23 ( & V_17 ) ;
while ( ( line = F_24 ( V_21 ) ) ) {
struct V_5 * V_13 ;
line -- ;
V_21 &= ~ ( 1UL << line ) ;
F_22 ( & V_17 ) ;
V_13 = F_5 ( 32 * V_7 + line ) ;
if ( V_13 )
V_19 = V_13 -> V_19 ;
F_23 ( & V_17 ) ;
if ( ! V_13 ) {
F_10 ( L_6 ,
line , V_7 ) ;
continue;
}
F_25 ( V_19 ) ;
}
}
}
int T_3 F_28 ( struct V_1 * V_1 , struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_34 . V_37 ;
unsigned int V_19 , V_38 , V_7 ;
V_38 = V_36 -> V_38 ;
for ( V_7 = 0 ; V_7 < V_32 ; V_7 ++ )
V_27 [ V_7 ] . V_1 = V_1 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
int V_22 ;
V_19 = V_38 + V_7 ;
V_22 = F_29 ( V_19 , & V_39 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_30 ( V_19 , V_9 + V_7 ) ;
if ( V_22 < 0 )
return V_22 ;
V_9 [ V_7 ] . V_1 = V_1 ;
V_9 [ V_7 ] . V_19 = V_19 ;
V_9 [ V_7 ] . V_10 = - V_28 ;
F_31 ( V_19 , V_40 ) ;
#ifdef F_32
F_33 ( V_19 , V_41 | V_42 ) ;
#endif
}
F_34 ( V_1 -> V_43 , V_1 ) ;
F_35 ( V_1 -> V_43 , F_26 ) ;
F_34 ( V_1 -> V_44 , V_1 ) ;
F_35 ( V_1 -> V_44 , F_20 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_1 , struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_34 . V_37 ;
unsigned int V_19 , V_38 ;
V_38 = V_36 -> V_38 ;
F_35 ( V_1 -> V_43 , NULL ) ;
F_34 ( V_1 -> V_43 , NULL ) ;
F_35 ( V_1 -> V_44 , NULL ) ;
F_34 ( V_1 -> V_44 , NULL ) ;
for ( V_19 = V_38 ; V_19 < V_38 + V_8 ; V_19 ++ ) {
#ifdef F_32
F_33 ( V_19 , 0 ) ;
#endif
F_29 ( V_19 , NULL ) ;
F_30 ( V_19 , NULL ) ;
}
}
