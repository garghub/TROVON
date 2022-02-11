static
int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 , V_5 , V_6 ;
volatile unsigned int * V_7 = & V_2 -> V_8 -> V_7 ;
F_2 ( & V_2 -> V_9 ) ;
do {
V_4 = * V_7 ;
if ( V_4 & V_10 )
V_5 = V_4 | V_11 ;
else {
V_5 = V_3 | V_10 |
( ( V_2 -> V_12 + V_2 -> V_13 > 1 ) ?
V_11 : 0 ) ;
}
V_6 = F_3 ( V_7 , V_4 , V_5 ) ;
} while ( V_6 != V_4 );
F_4 ( & V_2 -> V_9 ) ;
if ( F_5 ( V_4 ) == V_3 ) {
if ( V_4 & V_10 ) {
if ( V_3 != V_14 ) {
F_6 ( L_1 ,
V_3 ) ;
}
return 0 ;
}
}
if ( ( F_5 ( V_5 ) ) == V_3 && ( V_5 & V_10 ) ) {
return 1 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 , V_5 , V_6 ;
volatile unsigned int * V_7 = & V_2 -> V_8 -> V_7 ;
V_2 -> V_15 = NULL ;
do {
V_4 = * V_7 ;
V_5 = V_3 | V_10 ;
V_6 = F_3 ( V_7 , V_4 , V_5 ) ;
} while ( V_6 != V_4 );
return 1 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 , V_5 , V_6 ;
volatile unsigned int * V_7 = & V_2 -> V_8 -> V_7 ;
F_2 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_13 != 0 ) {
F_7 ( V_2 , 0 ) ;
V_2 -> V_16 = 1 ;
F_4 ( & V_2 -> V_9 ) ;
return 1 ;
}
F_4 ( & V_2 -> V_9 ) ;
do {
V_4 = * V_7 ;
V_5 = F_5 ( V_4 ) ;
V_6 = F_3 ( V_7 , V_4 , V_5 ) ;
} while ( V_6 != V_4 );
if ( F_9 ( V_4 ) && F_5 ( V_4 ) != V_3 ) {
F_6 ( L_2 ,
V_3 , F_5 ( V_4 ) ) ;
return 1 ;
}
F_10 ( & V_2 -> V_17 ) ;
return 0 ;
}
int F_11 ( struct V_18 * V_19 , void * V_20 ,
struct V_21 * V_15 )
{
F_12 ( V_22 , V_23 ) ;
struct V_24 * V_7 = V_20 ;
struct V_25 * V_26 = V_15 -> V_26 ;
int V_27 = 0 ;
if ( F_13 ( V_19 , V_28 ) )
return - V_29 ;
++ V_15 -> V_30 ;
if ( V_7 -> V_3 == V_14 ) {
F_6 ( L_3 ,
F_14 ( V_23 ) , V_7 -> V_3 ) ;
return - V_29 ;
}
F_15 ( L_4 ,
V_7 -> V_3 , F_14 ( V_23 ) ,
V_26 -> V_7 . V_8 -> V_7 , V_7 -> V_31 ) ;
F_16 ( & V_26 -> V_7 . V_17 , & V_22 ) ;
F_2 ( & V_26 -> V_7 . V_9 ) ;
V_26 -> V_7 . V_12 ++ ;
F_4 ( & V_26 -> V_7 . V_9 ) ;
for (; ; ) {
F_17 ( V_32 ) ;
if ( ! V_26 -> V_7 . V_8 ) {
F_18 ( V_33 , V_23 , 0 ) ;
V_27 = - V_34 ;
break;
}
if ( F_1 ( & V_26 -> V_7 , V_7 -> V_3 ) ) {
V_26 -> V_7 . V_15 = V_15 ;
V_26 -> V_7 . V_35 = V_36 ;
break;
}
F_19 ( & V_37 ) ;
F_20 () ;
F_21 ( & V_37 ) ;
if ( F_22 ( V_23 ) ) {
V_27 = - V_34 ;
break;
}
}
F_2 ( & V_26 -> V_7 . V_9 ) ;
V_26 -> V_7 . V_12 -- ;
F_4 ( & V_26 -> V_7 . V_9 ) ;
F_17 ( V_38 ) ;
F_23 ( & V_26 -> V_7 . V_17 , & V_22 ) ;
F_15 ( L_5 , V_7 -> V_3 ,
V_27 ? L_6 : L_7 ) ;
if ( V_27 ) return V_27 ;
if ( ! F_24 ( V_15 ) ) {
V_19 -> V_39 . V_3 = V_7 -> V_3 ;
V_19 -> V_39 . V_7 = V_26 -> V_7 . V_8 ;
}
if ( V_19 -> V_40 -> V_41 && ( V_7 -> V_31 & V_42 ) )
{
if ( V_19 -> V_40 -> V_41 ( V_19 ) ) {
F_15 ( L_8 ,
V_7 -> V_3 ) ;
return - V_43 ;
}
}
return 0 ;
}
int F_25 ( struct V_18 * V_19 , void * V_20 , struct V_21 * V_15 )
{
struct V_24 * V_7 = V_20 ;
struct V_25 * V_26 = V_15 -> V_26 ;
if ( F_13 ( V_19 , V_28 ) )
return - V_29 ;
if ( V_7 -> V_3 == V_14 ) {
F_6 ( L_3 ,
F_14 ( V_23 ) , V_7 -> V_3 ) ;
return - V_29 ;
}
if ( F_8 ( & V_26 -> V_7 , V_7 -> V_3 ) ) {
}
return 0 ;
}
void F_26 ( struct V_1 * V_2 )
{
int V_27 ;
F_2 ( & V_2 -> V_9 ) ;
V_2 -> V_13 ++ ;
if ( ! V_2 -> V_16 ) {
F_4 ( & V_2 -> V_9 ) ;
V_27 = F_1 ( V_2 , V_14 ) ;
F_2 ( & V_2 -> V_9 ) ;
if ( V_27 == 1 )
V_2 -> V_16 = 1 ;
}
F_4 ( & V_2 -> V_9 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
unsigned int V_4 , V_6 ;
volatile unsigned int * V_7 = & V_2 -> V_8 -> V_7 ;
F_2 ( & V_2 -> V_9 ) ;
if ( -- V_2 -> V_13 == 0 ) {
if ( V_2 -> V_16 ) {
do {
V_4 = * V_7 ;
V_6 = F_3 ( V_7 , V_4 , V_14 ) ;
} while ( V_6 != V_4 );
F_10 ( & V_2 -> V_17 ) ;
V_2 -> V_16 = 0 ;
}
}
F_4 ( & V_2 -> V_9 ) ;
}
static int F_28 ( struct V_18 * V_19 ,
struct V_21 * V_15 )
{
struct V_25 * V_26 = V_15 -> V_26 ;
return ( V_15 -> V_30 && V_26 -> V_7 . V_8 &&
F_9 ( V_26 -> V_7 . V_8 -> V_7 ) &&
V_26 -> V_7 . V_15 == V_15 ) ;
}
void F_29 ( struct V_18 * V_19 , struct V_44 * V_45 )
{
struct V_21 * V_15 = V_45 -> V_46 ;
if ( ! V_19 -> V_26 )
return;
if ( F_28 ( V_19 , V_15 ) ) {
F_15 ( L_9 ,
V_45 , F_5 ( V_15 -> V_26 -> V_7 . V_8 -> V_7 ) ) ;
F_8 ( & V_15 -> V_26 -> V_7 ,
F_5 ( V_15 -> V_26 -> V_7 . V_8 -> V_7 ) ) ;
}
}
