int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
F_2 ( V_6 , V_7 ) ;
struct V_8 * V_9 = V_3 ;
struct V_10 * V_11 = V_5 -> V_11 ;
int V_12 = 0 ;
if ( F_3 ( V_2 , V_13 ) )
return - V_14 ;
++ V_5 -> V_15 ;
if ( V_9 -> V_16 == V_17 ) {
F_4 ( L_1 ,
F_5 ( V_7 ) , V_9 -> V_16 ) ;
return - V_14 ;
}
F_6 ( L_2 ,
V_9 -> V_16 , F_5 ( V_7 ) ,
V_11 -> V_9 . V_18 -> V_9 , V_9 -> V_19 ) ;
F_7 ( & V_11 -> V_9 . V_20 , & V_6 ) ;
F_8 ( & V_11 -> V_9 . V_21 ) ;
V_11 -> V_9 . V_22 ++ ;
F_9 ( & V_11 -> V_9 . V_21 ) ;
for (; ; ) {
F_10 ( V_23 ) ;
if ( ! V_11 -> V_9 . V_18 ) {
F_11 ( V_24 , V_7 , 0 ) ;
V_12 = - V_25 ;
break;
}
if ( F_12 ( & V_11 -> V_9 , V_9 -> V_16 ) ) {
V_11 -> V_9 . V_5 = V_5 ;
V_11 -> V_9 . V_26 = V_27 ;
break;
}
F_13 ( & V_28 ) ;
F_14 () ;
F_15 ( & V_28 ) ;
if ( F_16 ( V_7 ) ) {
V_12 = - V_25 ;
break;
}
}
F_8 ( & V_11 -> V_9 . V_21 ) ;
V_11 -> V_9 . V_22 -- ;
F_9 ( & V_11 -> V_9 . V_21 ) ;
F_10 ( V_29 ) ;
F_17 ( & V_11 -> V_9 . V_20 , & V_6 ) ;
F_6 ( L_3 , V_9 -> V_16 ,
V_12 ? L_4 : L_5 ) ;
if ( V_12 ) return V_12 ;
if ( ! V_5 -> V_30 ) {
F_18 ( & V_2 -> V_31 ) ;
F_19 ( & V_2 -> V_31 , V_32 ) ;
F_19 ( & V_2 -> V_31 , V_33 ) ;
F_19 ( & V_2 -> V_31 , V_34 ) ;
F_19 ( & V_2 -> V_31 , V_35 ) ;
V_2 -> V_36 . V_16 = V_9 -> V_16 ;
V_2 -> V_36 . V_9 = V_11 -> V_9 . V_18 ;
F_20 ( V_37 , V_2 , & V_2 -> V_31 ) ;
}
if ( V_2 -> V_38 -> V_39 && ( V_9 -> V_19 & V_40 ) )
{
if ( V_2 -> V_38 -> V_39 ( V_2 ) ) {
F_6 ( L_6 ,
V_9 -> V_16 ) ;
return - V_41 ;
}
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_8 * V_9 = V_3 ;
struct V_10 * V_11 = V_5 -> V_11 ;
if ( F_3 ( V_2 , V_13 ) )
return - V_14 ;
if ( V_9 -> V_16 == V_17 ) {
F_4 ( L_1 ,
F_5 ( V_7 ) , V_9 -> V_16 ) ;
return - V_14 ;
}
if ( F_22 ( & V_11 -> V_9 , V_9 -> V_16 ) ) {
}
F_23 () ;
return 0 ;
}
static
int F_12 ( struct V_42 * V_43 ,
unsigned int V_16 )
{
unsigned int V_44 , V_45 , V_46 ;
volatile unsigned int * V_9 = & V_43 -> V_18 -> V_9 ;
F_8 ( & V_43 -> V_21 ) ;
do {
V_44 = * V_9 ;
if ( V_44 & V_47 )
V_45 = V_44 | V_48 ;
else {
V_45 = V_16 | V_47 |
( ( V_43 -> V_22 + V_43 -> V_49 > 1 ) ?
V_48 : 0 ) ;
}
V_46 = F_24 ( V_9 , V_44 , V_45 ) ;
} while ( V_46 != V_44 );
F_9 ( & V_43 -> V_21 ) ;
if ( F_25 ( V_44 ) == V_16 ) {
if ( V_44 & V_47 ) {
if ( V_16 != V_17 ) {
F_4 ( L_7 ,
V_16 ) ;
}
return 0 ;
}
}
if ( ( F_25 ( V_45 ) ) == V_16 && ( V_45 & V_47 ) ) {
return 1 ;
}
return 0 ;
}
static int F_26 ( struct V_42 * V_43 ,
unsigned int V_16 )
{
unsigned int V_44 , V_45 , V_46 ;
volatile unsigned int * V_9 = & V_43 -> V_18 -> V_9 ;
V_43 -> V_5 = NULL ;
do {
V_44 = * V_9 ;
V_45 = V_16 | V_47 ;
V_46 = F_24 ( V_9 , V_44 , V_45 ) ;
} while ( V_46 != V_44 );
return 1 ;
}
int F_22 ( struct V_42 * V_43 , unsigned int V_16 )
{
unsigned int V_44 , V_45 , V_46 ;
volatile unsigned int * V_9 = & V_43 -> V_18 -> V_9 ;
F_8 ( & V_43 -> V_21 ) ;
if ( V_43 -> V_49 != 0 ) {
F_26 ( V_43 , 0 ) ;
V_43 -> V_50 = 1 ;
F_9 ( & V_43 -> V_21 ) ;
return 1 ;
}
F_9 ( & V_43 -> V_21 ) ;
do {
V_44 = * V_9 ;
V_45 = F_25 ( V_44 ) ;
V_46 = F_24 ( V_9 , V_44 , V_45 ) ;
} while ( V_46 != V_44 );
if ( F_27 ( V_44 ) && F_25 ( V_44 ) != V_16 ) {
F_4 ( L_8 ,
V_16 , F_25 ( V_44 ) ) ;
return 1 ;
}
F_28 ( & V_43 -> V_20 ) ;
return 0 ;
}
static int V_37 ( void * V_51 )
{
struct V_1 * V_2 = V_51 ;
struct V_52 * V_9 = V_2 -> V_36 . V_9 ;
unsigned int V_44 , V_45 , V_46 ;
if ( ! V_9 || ! F_27 ( V_9 -> V_9 )
|| F_25 ( V_9 -> V_9 ) != V_2 -> V_36 . V_16 )
return 1 ;
do {
V_44 = V_9 -> V_9 ;
V_45 = V_44 | V_48 ;
V_46 = F_24 ( & V_9 -> V_9 , V_44 , V_45 ) ;
} while ( V_46 != V_44 );
return 0 ;
}
void F_29 ( struct V_42 * V_43 )
{
int V_12 ;
F_8 ( & V_43 -> V_21 ) ;
V_43 -> V_49 ++ ;
if ( ! V_43 -> V_50 ) {
F_9 ( & V_43 -> V_21 ) ;
V_12 = F_12 ( V_43 , V_17 ) ;
F_8 ( & V_43 -> V_21 ) ;
if ( V_12 == 1 )
V_43 -> V_50 = 1 ;
}
F_9 ( & V_43 -> V_21 ) ;
}
void F_30 ( struct V_42 * V_43 )
{
unsigned int V_44 , V_46 ;
volatile unsigned int * V_9 = & V_43 -> V_18 -> V_9 ;
F_8 ( & V_43 -> V_21 ) ;
if ( -- V_43 -> V_49 == 0 ) {
if ( V_43 -> V_50 ) {
do {
V_44 = * V_9 ;
V_46 = F_24 ( V_9 , V_44 , V_17 ) ;
} while ( V_46 != V_44 );
F_28 ( & V_43 -> V_20 ) ;
V_43 -> V_50 = 0 ;
}
}
F_9 ( & V_43 -> V_21 ) ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_10 * V_11 = V_5 -> V_11 ;
return ( V_5 -> V_15 && V_11 -> V_9 . V_18 &&
F_27 ( V_11 -> V_9 . V_18 -> V_9 ) &&
V_11 -> V_9 . V_5 == V_5 ) ;
}
