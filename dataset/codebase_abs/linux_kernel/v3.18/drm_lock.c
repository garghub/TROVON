int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
F_2 ( V_6 , V_7 ) ;
struct V_8 * V_9 = V_3 ;
struct V_10 * V_11 = V_5 -> V_11 ;
int V_12 = 0 ;
++ V_5 -> V_13 ;
if ( V_9 -> V_14 == V_15 ) {
F_3 ( L_1 ,
F_4 ( V_7 ) , V_9 -> V_14 ) ;
return - V_16 ;
}
F_5 ( L_2 ,
V_9 -> V_14 , F_4 ( V_7 ) ,
V_11 -> V_9 . V_17 -> V_9 , V_9 -> V_18 ) ;
F_6 ( & V_11 -> V_9 . V_19 , & V_6 ) ;
F_7 ( & V_11 -> V_9 . V_20 ) ;
V_11 -> V_9 . V_21 ++ ;
F_8 ( & V_11 -> V_9 . V_20 ) ;
for (; ; ) {
F_9 ( V_22 ) ;
if ( ! V_11 -> V_9 . V_17 ) {
F_10 ( V_23 , V_7 , 0 ) ;
V_12 = - V_24 ;
break;
}
if ( F_11 ( & V_11 -> V_9 , V_9 -> V_14 ) ) {
V_11 -> V_9 . V_5 = V_5 ;
V_11 -> V_9 . V_25 = V_26 ;
break;
}
F_12 ( & V_27 ) ;
F_13 () ;
F_14 ( & V_27 ) ;
if ( F_15 ( V_7 ) ) {
V_12 = - V_24 ;
break;
}
}
F_7 ( & V_11 -> V_9 . V_20 ) ;
V_11 -> V_9 . V_21 -- ;
F_8 ( & V_11 -> V_9 . V_20 ) ;
F_9 ( V_28 ) ;
F_16 ( & V_11 -> V_9 . V_19 , & V_6 ) ;
F_5 ( L_3 , V_9 -> V_14 ,
V_12 ? L_4 : L_5 ) ;
if ( V_12 ) return V_12 ;
if ( ! V_5 -> V_29 ) {
F_17 ( & V_2 -> V_30 ) ;
F_18 ( & V_2 -> V_30 , V_31 ) ;
F_18 ( & V_2 -> V_30 , V_32 ) ;
F_18 ( & V_2 -> V_30 , V_33 ) ;
F_18 ( & V_2 -> V_30 , V_34 ) ;
V_2 -> V_35 . V_14 = V_9 -> V_14 ;
V_2 -> V_35 . V_9 = V_11 -> V_9 . V_17 ;
F_19 ( V_36 , V_2 , & V_2 -> V_30 ) ;
}
if ( V_2 -> V_37 -> V_38 && ( V_9 -> V_18 & V_39 ) )
{
if ( V_2 -> V_37 -> V_38 ( V_2 ) ) {
F_5 ( L_6 ,
V_9 -> V_14 ) ;
return - V_40 ;
}
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_8 * V_9 = V_3 ;
struct V_10 * V_11 = V_5 -> V_11 ;
if ( V_9 -> V_14 == V_15 ) {
F_3 ( L_1 ,
F_4 ( V_7 ) , V_9 -> V_14 ) ;
return - V_16 ;
}
if ( F_21 ( & V_11 -> V_9 , V_9 -> V_14 ) ) {
}
F_22 () ;
return 0 ;
}
static
int F_11 ( struct V_41 * V_42 ,
unsigned int V_14 )
{
unsigned int V_43 , V_44 , V_45 ;
volatile unsigned int * V_9 = & V_42 -> V_17 -> V_9 ;
F_7 ( & V_42 -> V_20 ) ;
do {
V_43 = * V_9 ;
if ( V_43 & V_46 )
V_44 = V_43 | V_47 ;
else {
V_44 = V_14 | V_46 |
( ( V_42 -> V_21 + V_42 -> V_48 > 1 ) ?
V_47 : 0 ) ;
}
V_45 = F_23 ( V_9 , V_43 , V_44 ) ;
} while ( V_45 != V_43 );
F_8 ( & V_42 -> V_20 ) ;
if ( F_24 ( V_43 ) == V_14 ) {
if ( V_43 & V_46 ) {
if ( V_14 != V_15 ) {
F_3 ( L_7 ,
V_14 ) ;
}
return 0 ;
}
}
if ( ( F_24 ( V_44 ) ) == V_14 && ( V_44 & V_46 ) ) {
return 1 ;
}
return 0 ;
}
static int F_25 ( struct V_41 * V_42 ,
unsigned int V_14 )
{
unsigned int V_43 , V_44 , V_45 ;
volatile unsigned int * V_9 = & V_42 -> V_17 -> V_9 ;
V_42 -> V_5 = NULL ;
do {
V_43 = * V_9 ;
V_44 = V_14 | V_46 ;
V_45 = F_23 ( V_9 , V_43 , V_44 ) ;
} while ( V_45 != V_43 );
return 1 ;
}
int F_21 ( struct V_41 * V_42 , unsigned int V_14 )
{
unsigned int V_43 , V_44 , V_45 ;
volatile unsigned int * V_9 = & V_42 -> V_17 -> V_9 ;
F_7 ( & V_42 -> V_20 ) ;
if ( V_42 -> V_48 != 0 ) {
F_25 ( V_42 , 0 ) ;
V_42 -> V_49 = 1 ;
F_8 ( & V_42 -> V_20 ) ;
return 1 ;
}
F_8 ( & V_42 -> V_20 ) ;
do {
V_43 = * V_9 ;
V_44 = F_24 ( V_43 ) ;
V_45 = F_23 ( V_9 , V_43 , V_44 ) ;
} while ( V_45 != V_43 );
if ( F_26 ( V_43 ) && F_24 ( V_43 ) != V_14 ) {
F_3 ( L_8 ,
V_14 , F_24 ( V_43 ) ) ;
return 1 ;
}
F_27 ( & V_42 -> V_19 ) ;
return 0 ;
}
static int V_36 ( void * V_50 )
{
struct V_1 * V_2 = V_50 ;
struct V_51 * V_9 = V_2 -> V_35 . V_9 ;
unsigned int V_43 , V_44 , V_45 ;
if ( ! V_9 || ! F_26 ( V_9 -> V_9 )
|| F_24 ( V_9 -> V_9 ) != V_2 -> V_35 . V_14 )
return 1 ;
do {
V_43 = V_9 -> V_9 ;
V_44 = V_43 | V_47 ;
V_45 = F_23 ( & V_9 -> V_9 , V_43 , V_44 ) ;
} while ( V_45 != V_43 );
return 0 ;
}
void F_28 ( struct V_41 * V_42 )
{
int V_12 ;
F_7 ( & V_42 -> V_20 ) ;
V_42 -> V_48 ++ ;
if ( ! V_42 -> V_49 ) {
F_8 ( & V_42 -> V_20 ) ;
V_12 = F_11 ( V_42 , V_15 ) ;
F_7 ( & V_42 -> V_20 ) ;
if ( V_12 == 1 )
V_42 -> V_49 = 1 ;
}
F_8 ( & V_42 -> V_20 ) ;
}
void F_29 ( struct V_41 * V_42 )
{
unsigned int V_43 , V_45 ;
volatile unsigned int * V_9 = & V_42 -> V_17 -> V_9 ;
F_7 ( & V_42 -> V_20 ) ;
if ( -- V_42 -> V_48 == 0 ) {
if ( V_42 -> V_49 ) {
do {
V_43 = * V_9 ;
V_45 = F_23 ( V_9 , V_43 , V_15 ) ;
} while ( V_45 != V_43 );
F_27 ( & V_42 -> V_19 ) ;
V_42 -> V_49 = 0 ;
}
}
F_8 ( & V_42 -> V_20 ) ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_10 * V_11 = V_5 -> V_11 ;
return ( V_5 -> V_13 && V_11 -> V_9 . V_17 &&
F_26 ( V_11 -> V_9 . V_17 -> V_9 ) &&
V_11 -> V_9 . V_5 == V_5 ) ;
}
