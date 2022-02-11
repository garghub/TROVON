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
V_2 -> V_31 . V_16 = V_9 -> V_16 ;
V_2 -> V_31 . V_9 = V_11 -> V_9 . V_18 ;
}
if ( V_2 -> V_32 -> V_33 && ( V_9 -> V_19 & V_34 ) )
{
if ( V_2 -> V_32 -> V_33 ( V_2 ) ) {
F_6 ( L_6 ,
V_9 -> V_16 ) ;
return - V_35 ;
}
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
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
if ( F_19 ( & V_11 -> V_9 , V_9 -> V_16 ) ) {
}
return 0 ;
}
static
int F_12 ( struct V_36 * V_37 ,
unsigned int V_16 )
{
unsigned int V_38 , V_39 , V_40 ;
volatile unsigned int * V_9 = & V_37 -> V_18 -> V_9 ;
F_8 ( & V_37 -> V_21 ) ;
do {
V_38 = * V_9 ;
if ( V_38 & V_41 )
V_39 = V_38 | V_42 ;
else {
V_39 = V_16 | V_41 |
( ( V_37 -> V_22 + V_37 -> V_43 > 1 ) ?
V_42 : 0 ) ;
}
V_40 = F_20 ( V_9 , V_38 , V_39 ) ;
} while ( V_40 != V_38 );
F_9 ( & V_37 -> V_21 ) ;
if ( F_21 ( V_38 ) == V_16 ) {
if ( V_38 & V_41 ) {
if ( V_16 != V_17 ) {
F_4 ( L_7 ,
V_16 ) ;
}
return 0 ;
}
}
if ( ( F_21 ( V_39 ) ) == V_16 && ( V_39 & V_41 ) ) {
return 1 ;
}
return 0 ;
}
static int F_22 ( struct V_36 * V_37 ,
unsigned int V_16 )
{
unsigned int V_38 , V_39 , V_40 ;
volatile unsigned int * V_9 = & V_37 -> V_18 -> V_9 ;
V_37 -> V_5 = NULL ;
do {
V_38 = * V_9 ;
V_39 = V_16 | V_41 ;
V_40 = F_20 ( V_9 , V_38 , V_39 ) ;
} while ( V_40 != V_38 );
return 1 ;
}
int F_19 ( struct V_36 * V_37 , unsigned int V_16 )
{
unsigned int V_38 , V_39 , V_40 ;
volatile unsigned int * V_9 = & V_37 -> V_18 -> V_9 ;
F_8 ( & V_37 -> V_21 ) ;
if ( V_37 -> V_43 != 0 ) {
F_22 ( V_37 , 0 ) ;
V_37 -> V_44 = 1 ;
F_9 ( & V_37 -> V_21 ) ;
return 1 ;
}
F_9 ( & V_37 -> V_21 ) ;
do {
V_38 = * V_9 ;
V_39 = F_21 ( V_38 ) ;
V_40 = F_20 ( V_9 , V_38 , V_39 ) ;
} while ( V_40 != V_38 );
if ( F_23 ( V_38 ) && F_21 ( V_38 ) != V_16 ) {
F_4 ( L_8 ,
V_16 , F_21 ( V_38 ) ) ;
return 1 ;
}
F_24 ( & V_37 -> V_20 ) ;
return 0 ;
}
void F_25 ( struct V_36 * V_37 )
{
int V_12 ;
F_8 ( & V_37 -> V_21 ) ;
V_37 -> V_43 ++ ;
if ( ! V_37 -> V_44 ) {
F_9 ( & V_37 -> V_21 ) ;
V_12 = F_12 ( V_37 , V_17 ) ;
F_8 ( & V_37 -> V_21 ) ;
if ( V_12 == 1 )
V_37 -> V_44 = 1 ;
}
F_9 ( & V_37 -> V_21 ) ;
}
void F_26 ( struct V_36 * V_37 )
{
unsigned int V_38 , V_40 ;
volatile unsigned int * V_9 = & V_37 -> V_18 -> V_9 ;
F_8 ( & V_37 -> V_21 ) ;
if ( -- V_37 -> V_43 == 0 ) {
if ( V_37 -> V_44 ) {
do {
V_38 = * V_9 ;
V_40 = F_20 ( V_9 , V_38 , V_17 ) ;
} while ( V_40 != V_38 );
F_24 ( & V_37 -> V_20 ) ;
V_37 -> V_44 = 0 ;
}
}
F_9 ( & V_37 -> V_21 ) ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_10 * V_11 = V_5 -> V_11 ;
return ( V_5 -> V_15 && V_11 -> V_9 . V_18 &&
F_23 ( V_11 -> V_9 . V_18 -> V_9 ) &&
V_11 -> V_9 . V_5 == V_5 ) ;
}
