static int F_1 ( T_1 * V_1 , unsigned long V_2 , unsigned long V_3 ,
struct V_4 * V_5 )
{
T_2 * V_6 ;
int V_7 = 0 ;
V_6 = F_2 ( V_1 , V_2 ) ;
for (; ; ) {
V_7 = V_5 -> V_8 ( V_6 , V_2 , V_2 + V_9 , V_5 ) ;
if ( V_7 )
break;
V_2 += V_9 ;
if ( V_2 == V_3 )
break;
V_6 ++ ;
}
F_3 ( V_6 ) ;
return V_7 ;
}
static int F_4 ( T_3 * V_10 , unsigned long V_2 , unsigned long V_3 ,
struct V_4 * V_5 )
{
T_1 * V_1 ;
unsigned long V_11 ;
int V_7 = 0 ;
V_1 = F_5 ( V_10 , V_2 ) ;
do {
V_12:
V_11 = F_6 ( V_2 , V_3 ) ;
if ( F_7 ( * V_1 ) || ! V_5 -> V_13 ) {
if ( V_5 -> V_14 )
V_7 = V_5 -> V_14 ( V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
continue;
}
if ( V_5 -> V_15 )
V_7 = V_5 -> V_15 ( V_1 , V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
if ( ! V_5 -> V_8 )
continue;
F_8 ( V_5 -> V_13 , V_1 , V_2 ) ;
if ( F_9 ( V_1 ) )
goto V_12;
V_7 = F_1 ( V_1 , V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
} while ( V_1 ++ , V_2 = V_11 , V_2 != V_3 );
return V_7 ;
}
static int F_10 ( T_4 * V_16 , unsigned long V_2 , unsigned long V_3 ,
struct V_4 * V_5 )
{
T_3 * V_10 ;
unsigned long V_11 ;
int V_7 = 0 ;
V_10 = F_11 ( V_16 , V_2 ) ;
do {
V_12:
V_11 = F_12 ( V_2 , V_3 ) ;
if ( F_13 ( * V_10 ) || ! V_5 -> V_13 ) {
if ( V_5 -> V_14 )
V_7 = V_5 -> V_14 ( V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
continue;
}
if ( V_5 -> V_17 ) {
T_5 * V_18 = F_14 ( V_10 , V_5 -> V_13 ) ;
if ( V_18 ) {
V_7 = V_5 -> V_17 ( V_10 , V_2 , V_11 , V_5 ) ;
F_15 ( V_18 ) ;
if ( V_7 )
break;
continue;
}
}
F_16 ( V_5 -> V_13 , V_10 , V_2 ) ;
if ( F_13 ( * V_10 ) )
goto V_12;
if ( V_5 -> V_15 || V_5 -> V_8 )
V_7 = F_4 ( V_10 , V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
} while ( V_10 ++ , V_2 = V_11 , V_2 != V_3 );
return V_7 ;
}
static int F_17 ( T_6 * V_19 , unsigned long V_2 , unsigned long V_3 ,
struct V_4 * V_5 )
{
T_4 * V_16 ;
unsigned long V_11 ;
int V_7 = 0 ;
V_16 = F_18 ( V_19 , V_2 ) ;
do {
V_11 = F_19 ( V_2 , V_3 ) ;
if ( F_20 ( V_16 ) ) {
if ( V_5 -> V_14 )
V_7 = V_5 -> V_14 ( V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
continue;
}
if ( V_5 -> V_15 || V_5 -> V_8 )
V_7 = F_10 ( V_16 , V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
} while ( V_16 ++ , V_2 = V_11 , V_2 != V_3 );
return V_7 ;
}
static int F_21 ( unsigned long V_2 , unsigned long V_3 ,
struct V_4 * V_5 )
{
T_6 * V_19 ;
unsigned long V_11 ;
int V_7 = 0 ;
V_19 = F_22 ( V_5 -> V_20 , V_2 ) ;
do {
V_11 = F_23 ( V_2 , V_3 ) ;
if ( F_24 ( V_19 ) ) {
if ( V_5 -> V_14 )
V_7 = V_5 -> V_14 ( V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
continue;
}
if ( V_5 -> V_15 || V_5 -> V_8 )
V_7 = F_17 ( V_19 , V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
} while ( V_19 ++ , V_2 = V_11 , V_2 != V_3 );
return V_7 ;
}
static unsigned long F_25 ( struct V_21 * V_22 , unsigned long V_2 ,
unsigned long V_3 )
{
unsigned long V_23 = ( V_2 & F_26 ( V_22 ) ) + F_27 ( V_22 ) ;
return V_23 < V_3 ? V_23 : V_3 ;
}
static int F_28 ( unsigned long V_2 , unsigned long V_3 ,
struct V_4 * V_5 )
{
struct V_24 * V_13 = V_5 -> V_13 ;
struct V_21 * V_22 = F_29 ( V_13 ) ;
unsigned long V_11 ;
unsigned long V_25 = F_26 ( V_22 ) ;
unsigned long V_26 = F_27 ( V_22 ) ;
T_2 * V_6 ;
int V_7 = 0 ;
do {
V_11 = F_25 ( V_22 , V_2 , V_3 ) ;
V_6 = F_30 ( V_5 -> V_20 , V_2 & V_25 , V_26 ) ;
if ( V_6 && V_5 -> V_27 )
V_7 = V_5 -> V_27 ( V_6 , V_25 , V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
} while ( V_2 = V_11 , V_2 != V_3 );
return V_7 ;
}
static int F_28 ( unsigned long V_2 , unsigned long V_3 ,
struct V_4 * V_5 )
{
return 0 ;
}
static int F_31 ( unsigned long V_28 , unsigned long V_3 ,
struct V_4 * V_5 )
{
struct V_24 * V_13 = V_5 -> V_13 ;
if ( V_5 -> V_29 )
return V_5 -> V_29 ( V_28 , V_3 , V_5 ) ;
if ( V_13 -> V_30 & V_31 ) {
int V_7 = 1 ;
if ( V_5 -> V_14 )
V_7 = V_5 -> V_14 ( V_28 , V_3 , V_5 ) ;
return V_7 ? V_7 : 1 ;
}
return 0 ;
}
static int F_32 ( unsigned long V_28 , unsigned long V_3 ,
struct V_4 * V_5 )
{
int V_7 = 0 ;
struct V_24 * V_13 = V_5 -> V_13 ;
if ( V_13 && F_33 ( V_13 ) ) {
if ( V_5 -> V_27 )
V_7 = F_28 ( V_28 , V_3 , V_5 ) ;
} else
V_7 = F_21 ( V_28 , V_3 , V_5 ) ;
return V_7 ;
}
int F_34 ( unsigned long V_28 , unsigned long V_3 ,
struct V_4 * V_5 )
{
int V_7 = 0 ;
unsigned long V_11 ;
struct V_24 * V_13 ;
if ( V_28 >= V_3 )
return - V_32 ;
if ( ! V_5 -> V_20 )
return - V_32 ;
F_35 ( ! F_36 ( & V_5 -> V_20 -> V_33 ) , V_5 -> V_20 ) ;
V_13 = F_37 ( V_5 -> V_20 , V_28 ) ;
do {
if ( ! V_13 ) {
V_5 -> V_13 = NULL ;
V_11 = V_3 ;
} else if ( V_28 < V_13 -> V_34 ) {
V_5 -> V_13 = NULL ;
V_11 = F_38 ( V_3 , V_13 -> V_34 ) ;
} else {
V_5 -> V_13 = V_13 ;
V_11 = F_38 ( V_3 , V_13 -> V_35 ) ;
V_13 = V_13 -> V_36 ;
V_7 = F_31 ( V_28 , V_11 , V_5 ) ;
if ( V_7 > 0 ) {
V_7 = 0 ;
continue;
}
if ( V_7 < 0 )
break;
}
if ( V_5 -> V_13 || V_5 -> V_14 )
V_7 = F_32 ( V_28 , V_11 , V_5 ) ;
if ( V_7 )
break;
} while ( V_28 = V_11 , V_28 < V_3 );
return V_7 ;
}
int F_39 ( struct V_24 * V_13 , struct V_4 * V_5 )
{
int V_7 ;
if ( ! V_5 -> V_20 )
return - V_32 ;
F_40 ( ! F_36 ( & V_5 -> V_20 -> V_33 ) ) ;
F_40 ( ! V_13 ) ;
V_5 -> V_13 = V_13 ;
V_7 = F_31 ( V_13 -> V_34 , V_13 -> V_35 , V_5 ) ;
if ( V_7 > 0 )
return 0 ;
if ( V_7 < 0 )
return V_7 ;
return F_32 ( V_13 -> V_34 , V_13 -> V_35 , V_5 ) ;
}
