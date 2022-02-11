T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = 64 ;
char V_6 ;
if ( ! V_2 )
return V_7 ;
V_4 = V_2 -> V_4 ;
if ( ! V_4 ) {
F_2 ( F_3 ( V_2 , V_8 ) ) ;
return V_7 ;
}
F_4 ( & V_2 -> V_9 ) ;
while ( V_5 -- > 0 ) {
if ( F_2 ( F_3 ( V_2 , V_8 ) ) & 0x80 ) {
V_6 = F_2 ( F_3 ( V_2 , V_10 ) ) ;
if ( V_2 -> V_11 & V_12 ) {
F_5 ( V_2 -> V_13 , & V_6 , 1 ) ;
}
}
}
F_6 ( & V_2 -> V_9 ) ;
return V_14 ;
}
static int F_7 ( struct V_15 * V_16 )
{
unsigned long V_17 ;
struct V_1 * V_2 ;
unsigned int V_18 ;
V_2 = V_16 -> V_4 -> V_19 ;
V_18 = V_2 -> V_20 >= V_21
? V_22 | V_23 : 0 ;
F_8 ( & V_2 -> V_24 , V_17 ) ;
if ( V_2 -> V_11 & ~ V_18 ) {
F_9 ( & V_2 -> V_24 , V_17 ) ;
return - V_25 ;
}
V_2 -> V_11 |= V_26 ;
V_2 -> V_13 = V_16 ;
if ( ! ( V_2 -> V_11 & V_22 ) ) {
F_9 ( & V_2 -> V_24 , V_17 ) ;
F_10 ( V_2 ) ;
if ( V_2 -> V_20 >= V_21 )
F_11 ( V_2 , V_27 ) ;
} else {
F_9 ( & V_2 -> V_24 , V_17 ) ;
}
return 0 ;
}
static int F_12 ( struct V_15 * V_16 )
{
unsigned long V_17 ;
struct V_1 * V_2 ;
unsigned int V_18 ;
V_2 = V_16 -> V_4 -> V_19 ;
V_18 = V_2 -> V_20 >= V_21
? V_26 | V_12 : 0 ;
F_8 ( & V_2 -> V_24 , V_17 ) ;
if ( V_2 -> V_11 & ~ V_18 ) {
F_9 ( & V_2 -> V_24 , V_17 ) ;
return - V_25 ;
}
V_2 -> V_11 |= V_22 ;
V_2 -> V_28 = V_16 ;
if ( ! ( V_2 -> V_11 & V_26 ) ) {
F_9 ( & V_2 -> V_24 , V_17 ) ;
F_10 ( V_2 ) ;
if ( V_2 -> V_20 >= V_21 )
F_11 ( V_2 , V_27 ) ;
} else {
F_9 ( & V_2 -> V_24 , V_17 ) ;
}
return 0 ;
}
static int F_13 ( struct V_15 * V_16 )
{
unsigned long V_17 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_4 -> V_19 ;
F_8 ( & V_2 -> V_24 , V_17 ) ;
V_2 -> V_11 &= ~ ( V_26 | V_12 ) ;
V_2 -> V_13 = NULL ;
if ( ! ( V_2 -> V_11 & V_22 ) ) {
F_9 ( & V_2 -> V_24 , V_17 ) ;
F_10 ( V_2 ) ;
} else {
F_9 ( & V_2 -> V_24 , V_17 ) ;
}
return 0 ;
}
static int F_14 ( struct V_15 * V_16 )
{
unsigned long V_17 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_4 -> V_19 ;
F_8 ( & V_2 -> V_24 , V_17 ) ;
V_2 -> V_11 &= ~ ( V_22 | V_23 ) ;
V_2 -> V_28 = NULL ;
if ( ! ( V_2 -> V_11 & V_26 ) ) {
F_9 ( & V_2 -> V_24 , V_17 ) ;
F_10 ( V_2 ) ;
} else {
F_9 ( & V_2 -> V_24 , V_17 ) ;
}
return 0 ;
}
static void F_15 ( struct V_15 * V_16 , int V_29 )
{
unsigned long V_17 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_4 -> V_19 ;
F_8 ( & V_2 -> V_24 , V_17 ) ;
if ( V_29 ) {
if ( ! ( V_2 -> V_11 & V_12 ) ) {
if ( V_2 -> V_20 < V_21 )
F_11 ( V_2 , V_30 ) ;
V_2 -> V_11 |= V_12 ;
}
} else {
if ( V_2 -> V_11 & V_12 ) {
if ( V_2 -> V_20 < V_21 )
F_11 ( V_2 , V_30 ) ;
V_2 -> V_11 &= ~ V_12 ;
}
}
F_9 ( & V_2 -> V_24 , V_17 ) ;
}
static void F_16 ( struct V_15 * V_16 )
{
unsigned long V_17 ;
struct V_1 * V_2 ;
char V_6 ;
int V_5 = 32 ;
V_2 = V_16 -> V_4 -> V_19 ;
while ( V_5 -- > 0 ) {
F_8 ( & V_2 -> V_24 , V_17 ) ;
if ( F_17 ( V_16 , & V_6 , 1 ) != 1 ) {
V_2 -> V_11 &= ~ V_23 ;
F_18 ( & V_2 -> V_31 ) ;
F_9 ( & V_2 -> V_24 , V_17 ) ;
break;
}
if ( V_2 -> V_20 >= V_21 ) {
int V_32 = 8 ;
while ( ( F_2 ( F_3 ( V_2 , V_33 ) ) & 0x80 ) != 0 && -- V_32 > 0 )
;
if ( V_32 == 0 ) {
F_9 ( & V_2 -> V_24 , V_17 ) ;
break;
}
F_19 ( V_6 , F_3 ( V_2 , V_34 ) ) ;
} else {
F_11 ( V_2 , V_35 ) ;
F_11 ( V_2 , V_6 ) ;
}
F_20 ( V_16 , 1 ) ;
F_9 ( & V_2 -> V_24 , V_17 ) ;
}
}
static void F_21 ( unsigned long V_36 )
{
struct V_15 * V_16 = (struct V_15 * ) V_36 ;
struct V_1 * V_2 = V_16 -> V_4 -> V_19 ;
unsigned long V_17 ;
F_8 ( & V_2 -> V_24 , V_17 ) ;
F_22 ( & V_2 -> V_31 , 1 + V_37 ) ;
F_9 ( & V_2 -> V_24 , V_17 ) ;
F_16 ( V_16 ) ;
}
static void F_23 ( struct V_15 * V_16 , int V_29 )
{
unsigned long V_17 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_4 -> V_19 ;
F_8 ( & V_2 -> V_24 , V_17 ) ;
if ( V_29 ) {
if ( ! ( V_2 -> V_11 & V_23 ) ) {
F_24 ( & V_2 -> V_31 ,
F_21 ,
( unsigned long ) V_16 ) ;
F_22 ( & V_2 -> V_31 , 1 + V_37 ) ;
V_2 -> V_11 |= V_23 ;
}
} else {
if ( V_2 -> V_11 & V_23 ) {
V_2 -> V_11 &= ~ V_23 ;
}
}
F_9 ( & V_2 -> V_24 , V_17 ) ;
if ( V_29 )
F_16 ( V_16 ) ;
}
int F_25 ( struct V_1 * V_2 , int V_38 )
{
struct V_3 * V_4 ;
int V_39 ;
if ( ( V_39 = F_26 ( V_2 -> V_40 , L_1 , V_38 , 1 , 1 , & V_4 ) ) < 0 )
return V_39 ;
strcpy ( V_4 -> V_41 , L_1 ) ;
F_27 ( V_4 , V_42 , & V_43 ) ;
F_27 ( V_4 , V_44 , & V_45 ) ;
V_4 -> V_46 |= V_47 | V_48 ;
if ( V_2 -> V_20 >= V_21 )
V_4 -> V_46 |= V_49 ;
V_4 -> V_19 = V_2 ;
V_2 -> V_4 = V_4 ;
return 0 ;
}
