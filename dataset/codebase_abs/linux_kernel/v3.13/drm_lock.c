int F_1 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
F_2 ( V_6 , V_7 ) ;
struct F_1 * V_8 = V_3 ;
struct V_9 * V_10 = V_5 -> V_10 ;
int V_11 = 0 ;
++ V_5 -> V_12 ;
if ( V_8 -> V_13 == V_14 ) {
F_3 ( L_1 ,
F_4 ( V_7 ) , V_8 -> V_13 ) ;
return - V_15 ;
}
F_5 ( L_2 ,
V_8 -> V_13 , F_4 ( V_7 ) ,
V_10 -> V_8 . V_16 -> V_8 , V_8 -> V_17 ) ;
F_6 ( & V_10 -> V_8 . V_18 , & V_6 ) ;
F_7 ( & V_10 -> V_8 . V_19 ) ;
V_10 -> V_8 . V_20 ++ ;
F_8 ( & V_10 -> V_8 . V_19 ) ;
for (; ; ) {
F_9 ( V_21 ) ;
if ( ! V_10 -> V_8 . V_16 ) {
F_10 ( V_22 , V_7 , 0 ) ;
V_11 = - V_23 ;
break;
}
if ( F_11 ( & V_10 -> V_8 , V_8 -> V_13 ) ) {
V_10 -> V_8 . V_5 = V_5 ;
V_10 -> V_8 . V_24 = V_25 ;
break;
}
F_12 ( & V_26 ) ;
F_13 () ;
F_14 ( & V_26 ) ;
if ( F_15 ( V_7 ) ) {
V_11 = - V_23 ;
break;
}
}
F_7 ( & V_10 -> V_8 . V_19 ) ;
V_10 -> V_8 . V_20 -- ;
F_8 ( & V_10 -> V_8 . V_19 ) ;
F_9 ( V_27 ) ;
F_16 ( & V_10 -> V_8 . V_18 , & V_6 ) ;
F_5 ( L_3 , V_8 -> V_13 ,
V_11 ? L_4 : L_5 ) ;
if ( V_11 ) return V_11 ;
if ( ! V_5 -> V_28 ) {
F_17 ( & V_2 -> V_29 ) ;
F_18 ( & V_2 -> V_29 , V_30 ) ;
F_18 ( & V_2 -> V_29 , V_31 ) ;
F_18 ( & V_2 -> V_29 , V_32 ) ;
F_18 ( & V_2 -> V_29 , V_33 ) ;
V_2 -> V_34 . V_13 = V_8 -> V_13 ;
V_2 -> V_34 . V_8 = V_10 -> V_8 . V_16 ;
F_19 ( V_35 , & V_2 -> V_34 , & V_2 -> V_29 ) ;
}
if ( V_2 -> V_36 -> V_37 && ( V_8 -> V_17 & V_38 ) )
{
if ( V_2 -> V_36 -> V_37 ( V_2 ) ) {
F_5 ( L_6 ,
V_8 -> V_13 ) ;
return - V_39 ;
}
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct F_1 * V_8 = V_3 ;
struct V_9 * V_10 = V_5 -> V_10 ;
if ( V_8 -> V_13 == V_14 ) {
F_3 ( L_1 ,
F_4 ( V_7 ) , V_8 -> V_13 ) ;
return - V_15 ;
}
if ( F_21 ( & V_10 -> V_8 , V_8 -> V_13 ) ) {
}
F_22 () ;
return 0 ;
}
static
int F_11 ( struct V_40 * V_41 ,
unsigned int V_13 )
{
unsigned int V_42 , V_43 , V_44 ;
volatile unsigned int * V_8 = & V_41 -> V_16 -> V_8 ;
F_7 ( & V_41 -> V_19 ) ;
do {
V_42 = * V_8 ;
if ( V_42 & V_45 )
V_43 = V_42 | V_46 ;
else {
V_43 = V_13 | V_45 |
( ( V_41 -> V_20 + V_41 -> V_47 > 1 ) ?
V_46 : 0 ) ;
}
V_44 = F_23 ( V_8 , V_42 , V_43 ) ;
} while ( V_44 != V_42 );
F_8 ( & V_41 -> V_19 ) ;
if ( F_24 ( V_42 ) == V_13 ) {
if ( V_42 & V_45 ) {
if ( V_13 != V_14 ) {
F_3 ( L_7 ,
V_13 ) ;
}
return 0 ;
}
}
if ( ( F_24 ( V_43 ) ) == V_13 && ( V_43 & V_45 ) ) {
return 1 ;
}
return 0 ;
}
static int F_25 ( struct V_40 * V_41 ,
unsigned int V_13 )
{
unsigned int V_42 , V_43 , V_44 ;
volatile unsigned int * V_8 = & V_41 -> V_16 -> V_8 ;
V_41 -> V_5 = NULL ;
do {
V_42 = * V_8 ;
V_43 = V_13 | V_45 ;
V_44 = F_23 ( V_8 , V_42 , V_43 ) ;
} while ( V_44 != V_42 );
return 1 ;
}
int F_21 ( struct V_40 * V_41 , unsigned int V_13 )
{
unsigned int V_42 , V_43 , V_44 ;
volatile unsigned int * V_8 = & V_41 -> V_16 -> V_8 ;
F_7 ( & V_41 -> V_19 ) ;
if ( V_41 -> V_47 != 0 ) {
F_25 ( V_41 , 0 ) ;
V_41 -> V_48 = 1 ;
F_8 ( & V_41 -> V_19 ) ;
return 1 ;
}
F_8 ( & V_41 -> V_19 ) ;
do {
V_42 = * V_8 ;
V_43 = F_24 ( V_42 ) ;
V_44 = F_23 ( V_8 , V_42 , V_43 ) ;
} while ( V_44 != V_42 );
if ( F_26 ( V_42 ) && F_24 ( V_42 ) != V_13 ) {
F_3 ( L_8 ,
V_13 , F_24 ( V_42 ) ) ;
return 1 ;
}
F_27 ( & V_41 -> V_18 ) ;
return 0 ;
}
static int V_35 ( void * V_49 )
{
struct V_50 * V_51 = (struct V_50 * ) V_49 ;
unsigned int V_42 , V_43 , V_44 ;
if ( ! V_51 -> V_8 || ! F_26 ( V_51 -> V_8 -> V_8 )
|| F_24 ( V_51 -> V_8 -> V_8 ) != V_51 -> V_13 )
return 1 ;
do {
V_42 = V_51 -> V_8 -> V_8 ;
V_43 = V_42 | V_46 ;
V_44 = F_23 ( & V_51 -> V_8 -> V_8 , V_42 , V_43 ) ;
} while ( V_44 != V_42 );
return 0 ;
}
void F_28 ( struct V_40 * V_41 )
{
int V_11 ;
F_7 ( & V_41 -> V_19 ) ;
V_41 -> V_47 ++ ;
if ( ! V_41 -> V_48 ) {
F_8 ( & V_41 -> V_19 ) ;
V_11 = F_11 ( V_41 , V_14 ) ;
F_7 ( & V_41 -> V_19 ) ;
if ( V_11 == 1 )
V_41 -> V_48 = 1 ;
}
F_8 ( & V_41 -> V_19 ) ;
}
void F_29 ( struct V_40 * V_41 )
{
unsigned int V_42 , V_44 ;
volatile unsigned int * V_8 = & V_41 -> V_16 -> V_8 ;
F_7 ( & V_41 -> V_19 ) ;
if ( -- V_41 -> V_47 == 0 ) {
if ( V_41 -> V_48 ) {
do {
V_42 = * V_8 ;
V_44 = F_23 ( V_8 , V_42 , V_14 ) ;
} while ( V_44 != V_42 );
F_27 ( & V_41 -> V_18 ) ;
V_41 -> V_48 = 0 ;
}
}
F_8 ( & V_41 -> V_19 ) ;
}
int F_30 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_10 ;
return ( V_5 -> V_12 && V_10 -> V_8 . V_16 &&
F_26 ( V_10 -> V_8 . V_16 -> V_8 ) &&
V_10 -> V_8 . V_5 == V_5 ) ;
}
