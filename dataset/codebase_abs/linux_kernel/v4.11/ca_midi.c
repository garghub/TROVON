static void F_1 ( struct V_1 * V_2 )
{
int V_3 = 100000 ;
for (; V_3 > 0 && F_2 ( V_2 ) ; V_3 -- )
F_3 ( V_2 ) ;
#ifdef F_4
if ( V_3 <= 0 )
F_5 ( L_1 ,
F_6 ( V_2 ) ) ;
#endif
}
static void F_7 ( struct V_1 * V_2 , unsigned int V_4 )
{
unsigned char V_5 ;
if ( V_2 -> V_6 == NULL ) {
V_2 -> V_7 ( V_2 , V_2 -> V_8 | V_2 -> V_9 ) ;
return;
}
F_8 ( & V_2 -> V_10 ) ;
if ( ( V_4 & V_2 -> V_11 ) && F_2 ( V_2 ) ) {
if ( ! ( V_2 -> V_12 & V_13 ) ) {
F_1 ( V_2 ) ;
} else {
V_5 = F_3 ( V_2 ) ;
if( V_2 -> V_14 )
F_9 ( V_2 -> V_14 , & V_5 , 1 ) ;
}
}
F_10 ( & V_2 -> V_10 ) ;
F_8 ( & V_2 -> V_15 ) ;
if ( ( V_4 & V_2 -> V_16 ) && F_11 ( V_2 ) ) {
if ( V_2 -> V_17 &&
F_12 ( V_2 -> V_17 , & V_5 , 1 ) == 1 ) {
F_13 ( V_2 , V_5 ) ;
} else {
V_2 -> V_7 ( V_2 , V_2 -> V_8 ) ;
}
}
F_10 ( & V_2 -> V_15 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned char V_18 , int V_19 )
{
unsigned long V_20 ;
int V_3 , V_21 ;
F_15 ( & V_2 -> V_10 , V_20 ) ;
F_13 ( V_2 , 0x00 ) ;
F_16 ( V_2 , V_18 ) ;
if ( V_19 ) {
V_21 = 0 ;
V_3 = 10000 ;
while ( ! V_21 && V_3 -- > 0 ) {
if ( F_2 ( V_2 ) ) {
if ( F_3 ( V_2 ) == V_2 -> V_19 )
V_21 = 1 ;
}
}
if ( ! V_21 && F_3 ( V_2 ) == V_2 -> V_19 )
V_21 = 1 ;
} else {
V_21 = 1 ;
}
F_17 ( & V_2 -> V_10 , V_20 ) ;
if ( ! V_21 )
F_5 ( L_2 ,
V_18 ,
V_2 -> V_22 ( V_2 -> V_23 ) ,
F_6 ( V_2 ) ,
F_3 ( V_2 ) ) ;
}
static int F_18 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_6 -> V_26 ;
unsigned long V_20 ;
if ( F_19 ( ! V_2 -> V_23 ) )
return - V_27 ;
F_15 ( & V_2 -> V_28 , V_20 ) ;
V_2 -> V_12 |= V_13 ;
V_2 -> V_14 = V_25 ;
if ( ! ( V_2 -> V_12 & V_29 ) ) {
F_17 ( & V_2 -> V_28 , V_20 ) ;
F_14 ( V_2 , V_2 -> V_30 , 1 ) ;
F_14 ( V_2 , V_2 -> V_31 , 1 ) ;
} else {
F_17 ( & V_2 -> V_28 , V_20 ) ;
}
return 0 ;
}
static int F_20 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_6 -> V_26 ;
unsigned long V_20 ;
if ( F_19 ( ! V_2 -> V_23 ) )
return - V_27 ;
F_15 ( & V_2 -> V_28 , V_20 ) ;
V_2 -> V_12 |= V_29 ;
V_2 -> V_17 = V_25 ;
if ( ! ( V_2 -> V_12 & V_13 ) ) {
F_17 ( & V_2 -> V_28 , V_20 ) ;
F_14 ( V_2 , V_2 -> V_30 , 1 ) ;
F_14 ( V_2 , V_2 -> V_31 , 1 ) ;
} else {
F_17 ( & V_2 -> V_28 , V_20 ) ;
}
return 0 ;
}
static int F_21 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_6 -> V_26 ;
unsigned long V_20 ;
if ( F_19 ( ! V_2 -> V_23 ) )
return - V_27 ;
F_15 ( & V_2 -> V_28 , V_20 ) ;
V_2 -> V_7 ( V_2 , V_2 -> V_9 ) ;
V_2 -> V_12 &= ~ V_13 ;
V_2 -> V_14 = NULL ;
if ( ! ( V_2 -> V_12 & V_29 ) ) {
F_17 ( & V_2 -> V_28 , V_20 ) ;
F_14 ( V_2 , V_2 -> V_30 , 0 ) ;
} else {
F_17 ( & V_2 -> V_28 , V_20 ) ;
}
return 0 ;
}
static int F_22 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_6 -> V_26 ;
unsigned long V_20 ;
if ( F_19 ( ! V_2 -> V_23 ) )
return - V_27 ;
F_15 ( & V_2 -> V_28 , V_20 ) ;
V_2 -> V_7 ( V_2 , V_2 -> V_8 ) ;
V_2 -> V_12 &= ~ V_29 ;
V_2 -> V_17 = NULL ;
if ( ! ( V_2 -> V_12 & V_13 ) ) {
F_17 ( & V_2 -> V_28 , V_20 ) ;
F_14 ( V_2 , V_2 -> V_30 , 0 ) ;
} else {
F_17 ( & V_2 -> V_28 , V_20 ) ;
}
return 0 ;
}
static void F_23 ( struct V_24 * V_25 , int V_32 )
{
struct V_1 * V_2 = V_25 -> V_6 -> V_26 ;
if ( F_19 ( ! V_2 -> V_23 ) )
return;
if ( V_32 ) {
V_2 -> V_33 ( V_2 , V_2 -> V_9 ) ;
} else {
V_2 -> V_7 ( V_2 , V_2 -> V_9 ) ;
}
}
static void F_24 ( struct V_24 * V_25 , int V_32 )
{
struct V_1 * V_2 = V_25 -> V_6 -> V_26 ;
unsigned long V_20 ;
if ( F_19 ( ! V_2 -> V_23 ) )
return;
if ( V_32 ) {
int V_34 = 4 ;
unsigned char V_5 ;
F_15 ( & V_2 -> V_15 , V_20 ) ;
while ( V_34 > 0 ) {
if ( F_11 ( V_2 ) ) {
if ( ! ( V_2 -> V_12 & V_29 ) ||
F_12 ( V_25 , & V_5 , 1 ) != 1 ) {
F_17 ( & V_2 -> V_15 , V_20 ) ;
return;
}
F_13 ( V_2 , V_5 ) ;
V_34 -- ;
} else {
break;
}
}
F_17 ( & V_2 -> V_15 , V_20 ) ;
V_2 -> V_33 ( V_2 , V_2 -> V_8 ) ;
} else {
V_2 -> V_7 ( V_2 , V_2 -> V_8 ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_35 = NULL ;
V_2 -> V_33 = NULL ;
V_2 -> V_7 = NULL ;
V_2 -> V_36 = NULL ;
V_2 -> V_37 = NULL ;
V_2 -> V_38 = NULL ;
V_2 -> V_22 = NULL ;
V_2 -> V_6 = NULL ;
}
static void F_26 ( struct V_39 * V_6 )
{
F_25 ( V_6 -> V_26 ) ;
}
int F_27 ( void * V_23 , struct V_1 * V_2 , int V_40 , char * V_41 )
{
struct V_39 * V_6 ;
int V_42 ;
if ( ( V_42 = F_28 ( V_2 -> V_38 ( V_2 -> V_23 ) , V_41 , V_40 , 1 , 1 , & V_6 ) ) < 0 )
return V_42 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_35 = F_7 ;
F_29 ( & V_2 -> V_28 ) ;
F_29 ( & V_2 -> V_10 ) ;
F_29 ( & V_2 -> V_15 ) ;
strcpy ( V_6 -> V_41 , V_41 ) ;
F_30 ( V_6 , V_43 , & V_44 ) ;
F_30 ( V_6 , V_45 , & V_46 ) ;
V_6 -> V_47 |= V_48 |
V_49 |
V_50 ;
V_6 -> V_26 = V_2 ;
V_6 -> V_51 = F_26 ;
V_2 -> V_6 = V_6 ;
return 0 ;
}
