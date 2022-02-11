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
F_12 ( & V_2 -> V_26 [ V_27 ] ) ;
break;
}
F_13 ( & V_28 ) ;
F_14 () ;
F_15 ( & V_28 ) ;
if ( F_16 ( V_7 ) ) {
V_11 = - V_23 ;
break;
}
}
F_7 ( & V_10 -> V_8 . V_19 ) ;
V_10 -> V_8 . V_20 -- ;
F_8 ( & V_10 -> V_8 . V_19 ) ;
F_9 ( V_29 ) ;
F_17 ( & V_10 -> V_8 . V_18 , & V_6 ) ;
F_5 ( L_3 , V_8 -> V_13 ,
V_11 ? L_4 : L_5 ) ;
if ( V_11 ) return V_11 ;
if ( ! V_5 -> V_30 ) {
F_18 ( & V_2 -> V_31 ) ;
F_19 ( & V_2 -> V_31 , V_32 ) ;
F_19 ( & V_2 -> V_31 , V_33 ) ;
F_19 ( & V_2 -> V_31 , V_34 ) ;
F_19 ( & V_2 -> V_31 , V_35 ) ;
V_2 -> V_36 . V_13 = V_8 -> V_13 ;
V_2 -> V_36 . V_8 = V_10 -> V_8 . V_16 ;
F_20 ( V_37 , & V_2 -> V_36 , & V_2 -> V_31 ) ;
}
if ( V_2 -> V_38 -> V_39 && ( V_8 -> V_17 & V_40 ) )
{
if ( V_2 -> V_38 -> V_39 ( V_2 ) ) {
F_5 ( L_6 ,
V_8 -> V_13 ) ;
return - V_41 ;
}
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct F_1 * V_8 = V_3 ;
struct V_9 * V_10 = V_5 -> V_10 ;
if ( V_8 -> V_13 == V_14 ) {
F_3 ( L_1 ,
F_4 ( V_7 ) , V_8 -> V_13 ) ;
return - V_15 ;
}
F_12 ( & V_2 -> V_26 [ V_42 ] ) ;
if ( F_22 ( & V_10 -> V_8 , V_8 -> V_13 ) ) {
}
F_23 () ;
return 0 ;
}
static
int F_11 ( struct V_43 * V_44 ,
unsigned int V_13 )
{
unsigned int V_45 , V_46 , V_47 ;
volatile unsigned int * V_8 = & V_44 -> V_16 -> V_8 ;
F_7 ( & V_44 -> V_19 ) ;
do {
V_45 = * V_8 ;
if ( V_45 & V_48 )
V_46 = V_45 | V_49 ;
else {
V_46 = V_13 | V_48 |
( ( V_44 -> V_20 + V_44 -> V_50 > 1 ) ?
V_49 : 0 ) ;
}
V_47 = F_24 ( V_8 , V_45 , V_46 ) ;
} while ( V_47 != V_45 );
F_8 ( & V_44 -> V_19 ) ;
if ( F_25 ( V_45 ) == V_13 ) {
if ( V_45 & V_48 ) {
if ( V_13 != V_14 ) {
F_3 ( L_7 ,
V_13 ) ;
}
return 0 ;
}
}
if ( ( F_25 ( V_46 ) ) == V_13 && ( V_46 & V_48 ) ) {
return 1 ;
}
return 0 ;
}
static int F_26 ( struct V_43 * V_44 ,
unsigned int V_13 )
{
unsigned int V_45 , V_46 , V_47 ;
volatile unsigned int * V_8 = & V_44 -> V_16 -> V_8 ;
V_44 -> V_5 = NULL ;
do {
V_45 = * V_8 ;
V_46 = V_13 | V_48 ;
V_47 = F_24 ( V_8 , V_45 , V_46 ) ;
} while ( V_47 != V_45 );
return 1 ;
}
int F_22 ( struct V_43 * V_44 , unsigned int V_13 )
{
unsigned int V_45 , V_46 , V_47 ;
volatile unsigned int * V_8 = & V_44 -> V_16 -> V_8 ;
F_7 ( & V_44 -> V_19 ) ;
if ( V_44 -> V_50 != 0 ) {
F_26 ( V_44 , 0 ) ;
V_44 -> V_51 = 1 ;
F_8 ( & V_44 -> V_19 ) ;
return 1 ;
}
F_8 ( & V_44 -> V_19 ) ;
do {
V_45 = * V_8 ;
V_46 = F_25 ( V_45 ) ;
V_47 = F_24 ( V_8 , V_45 , V_46 ) ;
} while ( V_47 != V_45 );
if ( F_27 ( V_45 ) && F_25 ( V_45 ) != V_13 ) {
F_3 ( L_8 ,
V_13 , F_25 ( V_45 ) ) ;
return 1 ;
}
F_28 ( & V_44 -> V_18 ) ;
return 0 ;
}
static int V_37 ( void * V_52 )
{
struct V_53 * V_54 = (struct V_53 * ) V_52 ;
unsigned int V_45 , V_46 , V_47 ;
if ( ! V_54 -> V_8 || ! F_27 ( V_54 -> V_8 -> V_8 )
|| F_25 ( V_54 -> V_8 -> V_8 ) != V_54 -> V_13 )
return 1 ;
do {
V_45 = V_54 -> V_8 -> V_8 ;
V_46 = V_45 | V_49 ;
V_47 = F_24 ( & V_54 -> V_8 -> V_8 , V_45 , V_46 ) ;
} while ( V_47 != V_45 );
return 0 ;
}
void F_29 ( struct V_43 * V_44 )
{
int V_11 ;
F_7 ( & V_44 -> V_19 ) ;
V_44 -> V_50 ++ ;
if ( ! V_44 -> V_51 ) {
F_8 ( & V_44 -> V_19 ) ;
V_11 = F_11 ( V_44 , V_14 ) ;
F_7 ( & V_44 -> V_19 ) ;
if ( V_11 == 1 )
V_44 -> V_51 = 1 ;
}
F_8 ( & V_44 -> V_19 ) ;
}
void F_30 ( struct V_43 * V_44 )
{
unsigned int V_45 , V_47 ;
volatile unsigned int * V_8 = & V_44 -> V_16 -> V_8 ;
F_7 ( & V_44 -> V_19 ) ;
if ( -- V_44 -> V_50 == 0 ) {
if ( V_44 -> V_51 ) {
do {
V_45 = * V_8 ;
V_47 = F_24 ( V_8 , V_45 , V_14 ) ;
} while ( V_47 != V_45 );
F_28 ( & V_44 -> V_18 ) ;
V_44 -> V_51 = 0 ;
}
}
F_8 ( & V_44 -> V_19 ) ;
}
int F_31 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_10 ;
return ( V_5 -> V_12 && V_10 -> V_8 . V_16 &&
F_27 ( V_10 -> V_8 . V_16 -> V_8 ) &&
V_10 -> V_8 . V_5 == V_5 ) ;
}
