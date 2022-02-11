static void F_1 ( const char * V_1 ,
struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_5 = V_3 -> V_6 [ V_6 ] . V_8 ;
if ( ! V_5 )
continue;
F_2 ( V_9 L_1
L_2 , V_1 , V_6 ,
F_3 ( V_5 -> V_10 ) ,
F_3 ( V_5 -> V_11 ) ,
F_3 ( V_5 -> V_12 ) ,
F_3 ( V_5 -> V_13 ) ,
F_3 ( V_5 -> V_14 ) ) ;
}
}
static inline void T_1 * F_4 ( unsigned int V_6 )
{
return V_15 + ( V_6 << 2 ) ;
}
static inline int F_5 ( unsigned long V_16 )
{
return ! ( V_16 & V_17 ) ;
}
static inline unsigned int F_6 ( unsigned int V_18 , unsigned int V_19 )
{
if ( V_18 == 0 )
return 0 ;
return F_7 ( V_18 , V_19 ) ;
}
static unsigned int F_8 ( unsigned int V_18 , unsigned long V_19 ,
unsigned long * V_20 , int V_21 )
{
unsigned int div = F_6 ( V_18 , V_19 ) ;
unsigned long V_22 ;
F_9 ( L_3 ,
V_23 , V_18 , V_19 , V_21 , div ) ;
switch ( div ) {
case 0 :
V_22 = 0 ;
break;
case 1 :
V_22 = 1 ;
break;
case 2 :
V_22 = 2 ;
break;
case 3 :
case 4 :
V_22 = 3 ;
break;
default:
return - 1 ;
}
* V_20 |= V_22 << V_21 ;
return 0 ;
}
int F_10 ( unsigned int V_18 , unsigned long V_24 , unsigned long * V_20 )
{
return 0 ;
}
static int F_11 ( unsigned int V_18 , int V_25 ,
unsigned long V_19 , unsigned long * V_20 )
{
unsigned int div = F_6 ( V_18 , V_19 ) ;
unsigned long V_22 ;
F_9 ( L_4 ,
V_23 , V_18 , V_25 , V_19 , div ) ;
if ( V_25 && div < 4 )
div = 4 ;
switch ( div ) {
case 0 :
V_22 = 0 ;
break;
case 1 :
case 2 :
case 3 :
case 4 :
V_22 = div - 1 ;
break;
case 5 :
case 6 :
V_22 = 4 ;
break;
case 7 :
case 8 :
V_22 = 5 ;
break;
case 9 :
case 10 :
V_22 = 6 ;
break;
case 11 :
case 12 :
case 13 :
case 14 :
V_22 = 7 ;
break;
default:
return - 1 ;
}
* V_20 |= V_22 << 8 ;
return 0 ;
}
static int F_12 ( struct V_26 * V_27 ,
struct V_4 * V_5 )
{
unsigned long V_24 = V_27 -> V_28 . V_19 ;
unsigned long V_29 ;
int V_30 ;
V_29 = V_5 -> V_16 ;
V_29 &= ( V_17 | V_31 ) ;
V_30 = F_8 ( V_5 -> V_10 , V_24 , & V_29 , V_32 ) ;
V_30 |= F_8 ( V_5 -> V_11 , V_24 , & V_29 , V_33 ) ;
V_30 |= F_8 ( V_5 -> V_14 , V_24 , & V_29 , V_34 ) ;
V_30 |= F_8 ( V_5 -> V_13 , V_24 , & V_29 , V_35 ) ;
if ( V_30 )
return - V_36 ;
V_30 |= F_10 ( V_5 -> V_37 , V_24 , & V_29 ) ;
V_30 |= F_11 ( V_5 -> V_12 , V_5 -> V_25 , V_24 , & V_29 ) ;
if ( V_30 )
return - V_36 ;
V_5 -> V_16 = V_29 ;
return 0 ;
}
static unsigned int F_13 ( unsigned long V_19 ,
unsigned long V_22 )
{
V_22 &= 7 ;
return V_19 * V_38 [ V_22 ] ;
}
static unsigned int F_14 ( unsigned long V_19 ,
unsigned long V_22 )
{
V_22 &= 3 ;
return V_19 * ( ( V_22 == 3 ) ? 4 : V_22 ) ;
}
void F_15 ( struct V_26 * V_27 ,
struct V_4 * V_5 )
{
unsigned long V_16 = V_5 -> V_16 ;
unsigned long V_24 = V_27 -> V_28 . V_19 ;
V_5 -> V_14 = F_14 ( V_24 , V_16 >> V_34 ) ;
V_5 -> V_13 = F_14 ( V_24 , V_16 >> V_35 ) ;
V_5 -> V_11 = F_14 ( V_24 , V_16 >> V_33 ) ;
V_5 -> V_10 = F_14 ( V_24 , V_16 >> V_32 ) ;
V_5 -> V_12 = F_13 ( V_24 , V_16 >> V_39 ) ;
}
void F_16 ( struct V_40 * V_41 ,
struct V_26 * V_27 ,
union V_42 * V_43 )
{
struct V_4 * V_5 = V_43 -> V_8 ;
unsigned long V_16 = V_5 -> V_16 ;
unsigned long V_24 = V_27 -> V_28 . V_19 ;
unsigned int V_10 ;
unsigned int V_11 ;
unsigned int V_12 ;
unsigned int V_13 ;
unsigned int V_14 ;
F_17 ( V_41 , L_5 , V_16 ) ;
V_14 = F_14 ( V_24 , V_16 >> V_34 ) ;
V_13 = F_14 ( V_24 , V_16 >> V_35 ) ;
V_11 = F_14 ( V_24 , V_16 >> V_33 ) ;
V_10 = F_14 ( V_24 , V_16 >> V_32 ) ;
V_12 = F_13 ( V_24 , V_16 >> V_39 ) ;
F_17 ( V_41 ,
L_6 ,
F_3 ( V_5 -> V_10 ) ,
F_3 ( V_5 -> V_11 ) ,
F_3 ( V_5 -> V_12 ) ,
F_3 ( V_5 -> V_13 ) ,
F_3 ( V_5 -> V_14 ) ) ;
F_17 ( V_41 ,
L_7 ,
F_3 ( V_10 ) ,
F_3 ( V_11 ) ,
F_3 ( V_12 ) ,
F_3 ( V_13 ) ,
F_3 ( V_14 ) ) ;
}
int F_18 ( struct V_26 * V_27 ,
struct V_2 * V_44 )
{
struct V_4 * V_5 ;
unsigned long V_16 ;
int V_6 ;
int V_30 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_16 = F_19 ( F_4 ( V_6 ) ) ;
V_5 = V_44 -> V_6 [ V_6 ] . V_8 ;
if ( ! V_5 )
continue;
V_5 -> V_16 = V_16 ;
V_30 = F_12 ( V_27 , V_5 ) ;
if ( V_30 ) {
F_2 ( V_45 L_8 ,
V_23 , V_6 ) ;
goto V_46;
}
F_9 ( L_9 ,
V_23 , V_6 , V_5 -> V_16 ) ;
}
return 0 ;
V_46:
return V_30 ;
}
void F_20 ( struct V_26 * V_27 ,
struct V_2 * V_44 )
{
struct V_4 * V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_5 = V_44 -> V_6 [ V_6 ] . V_8 ;
if ( ! V_5 )
continue;
F_21 ( V_5 -> V_16 , F_4 ( V_6 ) ) ;
}
}
int F_22 ( struct V_26 * V_27 ,
struct V_2 * V_3 )
{
struct V_4 * V_5 ;
unsigned long V_16 ;
unsigned long V_47 ;
int V_6 ;
V_47 = F_19 ( V_48 ) ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_16 = F_19 ( F_4 ( V_6 ) ) ;
if ( ! F_5 ( V_16 ) )
continue;
F_9 ( L_10 ,
V_23 , V_6 , V_16 ) ;
V_5 = F_23 ( sizeof( struct V_4 ) , V_49 ) ;
if ( ! V_5 ) {
F_2 ( V_45 L_11 , V_23 ) ;
return - V_50 ;
}
if ( V_6 != 0 ) {
unsigned long V_51 = F_24 ( V_47 , V_6 ) ;
if ( V_51 & V_52 )
V_5 -> V_25 = 1 ;
}
V_3 -> V_6 [ V_6 ] . V_8 = V_5 ;
V_5 -> V_16 = V_16 ;
F_15 ( V_27 , V_5 ) ;
}
F_1 ( L_12 , V_3 ) ;
return 0 ;
}
