static struct V_1 *
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
unsigned long V_5 = V_2 -> V_6 , V_7 = V_2 -> V_8 - V_3 ;
unsigned long V_9 ;
struct V_1 * V_10 , * V_11 ;
V_11 = F_2 ( sizeof( struct V_1 ) , V_4 ) ;
if ( ! V_11 )
goto V_12;
F_3 ( & V_13 , V_9 ) ;
F_4 (c, &head->vm_list, vm_list) {
if ( ( V_5 + V_3 ) < V_5 )
goto V_14;
if ( ( V_5 + V_3 ) <= V_10 -> V_6 )
goto V_15;
V_5 = V_10 -> V_8 ;
if ( V_5 > V_7 )
goto V_14;
}
V_15:
F_5 ( & V_11 -> V_16 , & V_10 -> V_16 ) ;
V_11 -> V_6 = V_5 ;
V_11 -> V_8 = V_5 + V_3 ;
F_6 ( & V_13 , V_9 ) ;
return V_11 ;
V_14:
F_6 ( & V_13 , V_9 ) ;
F_7 ( V_11 ) ;
V_12:
return NULL ;
}
static struct V_1 * F_8 ( struct V_1 * V_2 , unsigned long V_5 )
{
struct V_1 * V_10 ;
F_4 (c, &head->vm_list, vm_list) {
if ( V_10 -> V_6 == V_5 )
goto V_12;
}
V_10 = NULL ;
V_12:
return V_10 ;
}
void *
F_9 ( struct V_17 * V_18 , T_1 V_3 , T_3 * V_19 , T_2 V_4 )
{
struct V_20 * V_20 ;
struct V_1 * V_10 ;
unsigned long V_21 ;
T_4 V_22 = V_23 , V_24 ;
if ( V_18 ) {
V_22 = V_18 -> V_25 ;
if ( V_22 == 0 ) {
F_10 ( V_18 , L_1 ) ;
goto V_26;
}
if ( ( ~ V_22 ) & V_23 ) {
F_10 ( V_18 , L_2
L_3 ,
V_22 , ( unsigned long long ) V_23 ) ;
goto V_26;
}
}
V_3 = F_11 ( V_3 ) ;
V_24 = ( V_22 + 1 ) & ~ V_22 ;
if ( ( V_24 && V_3 >= V_24 ) ||
V_3 >= ( V_27 - V_28 ) ) {
F_12 ( V_29 L_4 ,
V_3 , V_22 ) ;
return NULL ;
}
V_21 = F_13 ( V_3 ) ;
if ( V_22 != 0xffffffff )
V_4 |= V_30 ;
V_20 = F_14 ( V_4 , V_21 ) ;
if ( ! V_20 )
goto V_26;
{
unsigned long V_31 = ( unsigned long ) F_15 ( V_20 ) ;
memset ( F_15 ( V_20 ) , 0 , V_3 ) ;
F_16 ( V_31 , V_31 + V_3 ) ;
}
V_10 = F_1 ( & V_32 , V_3 ,
V_4 & ~ ( V_33 | V_34 ) ) ;
if ( V_10 ) {
unsigned long V_35 = V_10 -> V_6 ;
struct V_20 * V_7 = V_20 + ( 1 << V_21 ) ;
F_17 ( V_20 , V_21 ) ;
* V_19 = F_18 ( V_20 ) ;
do {
F_19 ( V_20 ) ;
F_20 ( V_35 , F_18 ( V_20 ) ,
F_21 ( V_36 ) ) ;
V_20 ++ ;
V_35 += V_37 ;
} while ( V_3 -= V_37 );
while ( V_20 < V_7 ) {
F_22 ( V_20 ) ;
V_20 ++ ;
}
return ( void * ) V_10 -> V_6 ;
}
if ( V_20 )
F_23 ( V_20 , V_21 ) ;
V_26:
return NULL ;
}
void F_24 ( T_1 V_3 , void * V_35 )
{
struct V_1 * V_10 ;
unsigned long V_9 , V_5 ;
V_3 = F_11 ( V_3 ) ;
F_3 ( & V_13 , V_9 ) ;
V_10 = F_8 ( & V_32 , ( unsigned long ) V_35 ) ;
if ( ! V_10 )
goto V_38;
if ( ( V_10 -> V_8 - V_10 -> V_6 ) != V_3 ) {
F_12 ( V_39 L_5 ,
V_40 , V_10 -> V_8 - V_10 -> V_6 , V_3 ) ;
F_25 () ;
V_3 = V_10 -> V_8 - V_10 -> V_6 ;
}
V_5 = V_10 -> V_6 ;
do {
T_5 * V_41 ;
unsigned long V_42 ;
V_41 = F_26 ( F_27 ( F_28 ( F_29 ( V_5 ) ,
V_5 ) ,
V_5 ) ,
V_5 ) ;
if ( ! F_30 ( * V_41 ) && F_31 ( * V_41 ) ) {
V_42 = F_32 ( * V_41 ) ;
F_33 ( & V_43 , V_5 , V_41 ) ;
if ( F_34 ( V_42 ) ) {
struct V_20 * V_20 = F_35 ( V_42 ) ;
F_36 ( V_20 ) ;
F_22 ( V_20 ) ;
}
}
V_5 += V_37 ;
} while ( V_3 -= V_37 );
F_37 ( V_10 -> V_6 , V_10 -> V_8 ) ;
F_38 ( & V_10 -> V_16 ) ;
F_6 ( & V_13 , V_9 ) ;
F_7 ( V_10 ) ;
return;
V_38:
F_6 ( & V_13 , V_9 ) ;
F_12 ( V_39 L_6 ,
V_40 , V_35 ) ;
F_25 () ;
}
void F_39 ( void * V_35 , T_1 V_3 , int V_44 )
{
unsigned long V_45 = ( unsigned long ) V_35 ;
unsigned long V_7 = V_45 + V_3 ;
switch ( V_44 ) {
case V_46 :
F_40 () ;
case V_47 :
if ( ( V_45 & ( V_48 - 1 ) ) || ( V_3 & ( V_48 - 1 ) ) )
F_16 ( V_45 , V_7 ) ;
else
F_41 ( V_45 , V_7 ) ;
break;
case V_49 :
F_42 ( V_45 , V_7 ) ;
break;
case V_50 :
F_16 ( V_45 , V_7 ) ;
break;
}
}
static inline void F_43 ( struct V_20 * V_20 ,
unsigned long V_51 , T_1 V_3 , int V_44 )
{
T_1 V_52 = F_44 ( ( T_1 ) ( V_37 - V_51 ) , V_3 ) ;
T_1 V_53 = V_52 ;
unsigned long V_9 , V_45 , V_54 = V_51 ;
int V_55 = 1 + ( ( V_3 - V_52 ) + V_37 - 1 ) / V_37 ;
int V_56 = 0 ;
F_45 ( V_9 ) ;
do {
V_45 = ( unsigned long ) F_46 ( V_20 + V_56 ,
V_57 ) + V_54 ;
F_39 ( ( void * ) V_45 , V_52 , V_44 ) ;
F_47 ( ( void * ) V_45 , V_57 ) ;
V_56 ++ ;
V_52 = F_44 ( ( T_1 ) V_37 , V_3 - V_53 ) ;
V_53 += V_52 ;
V_54 = 0 ;
} while ( V_56 < V_55 );
F_48 ( V_9 ) ;
}
void F_49 ( struct V_20 * V_20 , unsigned long V_51 ,
T_1 V_3 , int V_44 )
{
#ifdef F_50
F_43 ( V_20 , V_51 , V_3 , V_44 ) ;
#else
unsigned long V_45 = ( unsigned long ) F_15 ( V_20 ) + V_51 ;
F_39 ( ( void * ) V_45 , V_3 , V_44 ) ;
#endif
}
unsigned long F_51 ( unsigned long V_58 )
{
T_6 * V_59 = F_29 ( V_58 ) ;
T_7 * V_60 = F_28 ( V_59 , V_58 ) ;
T_8 * V_61 = F_27 ( V_60 , V_58 ) ;
T_5 * V_41 = F_26 ( V_61 , V_58 ) ;
if ( F_30 ( * V_41 ) || ! F_31 ( * V_41 ) )
return 0 ;
return F_32 ( * V_41 ) ;
}
