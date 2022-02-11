void F_1 ( struct V_1 * V_2 , const char * V_3 ,
struct V_4 * V_5 )
{
#ifdef F_2
F_3 ( ( void * ) V_2 , sizeof( * V_2 ) ) ;
F_4 ( & V_2 -> V_6 , V_3 , V_5 , 0 ) ;
#endif
V_2 -> V_7 = V_8 ;
F_5 ( & V_2 -> V_9 ) ;
F_6 ( & V_2 -> V_10 ) ;
}
static struct V_1 *
F_7 ( struct V_1 * V_2 , int V_11 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
signed long V_18 , V_19 , V_20 ;
V_13 = F_8 ( V_2 -> V_10 . V_17 , struct V_12 , V_21 ) ;
if ( ! ( V_13 -> V_22 & V_23 ) )
goto V_24;
if ( V_11 == V_25 )
goto V_26;
F_9 ( V_13 -> V_27 ) ;
goto V_26;
V_24:
if ( V_11 == V_28 &&
F_10 ( 0 , V_2 ) < V_29 )
goto V_26;
V_18 = 0 ;
do {
V_18 ++ ;
if ( V_13 -> V_21 . V_17 == & V_2 -> V_10 )
break;
V_13 = F_8 ( V_13 -> V_21 . V_17 ,
struct V_12 , V_21 ) ;
} while ( V_13 -> V_22 & V_30 );
V_20 = V_18 * V_31 ;
if ( V_13 -> V_22 & V_30 )
V_20 -= V_29 ;
F_11 ( V_20 , V_2 ) ;
V_17 = V_2 -> V_10 . V_17 ;
for ( V_19 = V_18 ; V_19 > 0 ; V_19 -- ) {
V_13 = F_8 ( V_17 , struct V_12 , V_21 ) ;
V_17 = V_13 -> V_21 . V_17 ;
V_15 = V_13 -> V_27 ;
F_12 () ;
V_13 -> V_27 = NULL ;
F_9 ( V_15 ) ;
F_13 ( V_15 ) ;
}
V_2 -> V_10 . V_17 = V_17 ;
V_17 -> V_32 = & V_2 -> V_10 ;
V_26:
return V_2 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_12 * V_33 ;
long V_34 , V_20 ;
V_33 = F_8 ( V_2 -> V_10 . V_17 , struct V_12 , V_21 ) ;
if ( ! ( V_33 -> V_22 & V_23 ) )
return 0 ;
V_20 = V_35 ;
if ( V_33 == V_13 && V_13 -> V_21 . V_17 == & V_2 -> V_10 )
V_20 -= V_29 ;
V_36:
V_34 = F_10 ( V_20 , V_2 ) - V_20 ;
if ( ! ( V_34 & V_37 ) ) {
struct V_14 * V_15 = V_13 -> V_27 ;
F_15 ( & V_13 -> V_21 ) ;
F_12 () ;
F_13 ( V_15 ) ;
V_15 -> V_38 = V_39 ;
return 1 ;
}
if ( F_10 ( - V_20 , V_2 ) & V_37 )
return 0 ;
goto V_36;
}
static struct V_1 T_1 *
F_16 ( struct V_1 * V_2 ,
unsigned int V_22 , signed long V_20 )
{
struct V_12 V_13 ;
struct V_14 * V_15 = V_40 ;
signed long V_7 ;
F_17 ( V_15 , V_41 ) ;
F_18 ( & V_2 -> V_9 ) ;
V_13 . V_27 = V_15 ;
V_13 . V_22 = V_22 ;
F_19 ( V_15 ) ;
if ( F_20 ( & V_2 -> V_10 ) )
V_20 += V_29 ;
F_21 ( & V_13 . V_21 , & V_2 -> V_10 ) ;
V_7 = F_10 ( V_20 , V_2 ) ;
if ( V_7 == V_29 )
V_2 = F_7 ( V_2 , V_42 ) ;
else if ( V_7 > V_29 &&
V_20 == - V_35 )
V_2 = F_7 ( V_2 , V_25 ) ;
F_22 ( & V_2 -> V_9 ) ;
for (; ; ) {
if ( ! V_13 . V_27 )
break;
F_18 ( & V_2 -> V_9 ) ;
if ( V_22 == V_23 )
if ( F_14 ( V_2 , & V_13 ) ) {
F_22 ( & V_2 -> V_9 ) ;
return V_2 ;
}
F_22 ( & V_2 -> V_9 ) ;
F_23 () ;
F_17 ( V_15 , V_41 ) ;
}
V_15 -> V_38 = V_39 ;
return V_2 ;
}
struct V_1 T_1 * F_24 ( struct V_1 * V_2 )
{
return F_16 ( V_2 , V_30 ,
- V_31 ) ;
}
struct V_1 T_1 * F_25 ( struct V_1 * V_2 )
{
return F_16 ( V_2 , V_23 ,
- V_35 ) ;
}
struct V_1 * F_26 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
F_27 ( & V_2 -> V_9 , V_22 ) ;
if ( ! F_20 ( & V_2 -> V_10 ) )
V_2 = F_7 ( V_2 , V_28 ) ;
F_28 ( & V_2 -> V_9 , V_22 ) ;
return V_2 ;
}
struct V_1 * F_29 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
F_27 ( & V_2 -> V_9 , V_22 ) ;
if ( ! F_20 ( & V_2 -> V_10 ) )
V_2 = F_7 ( V_2 , V_25 ) ;
F_28 ( & V_2 -> V_9 , V_22 ) ;
return V_2 ;
}
