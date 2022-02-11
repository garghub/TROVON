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
signed long V_18 , V_19 , V_20 , V_21 ;
V_13 = F_8 ( V_2 -> V_10 . V_17 , struct V_12 , V_22 ) ;
if ( ! ( V_13 -> V_23 & V_24 ) )
goto V_25;
if ( V_11 == V_26 )
goto V_27;
V_21 = V_28 ;
if ( V_13 -> V_22 . V_17 == & V_2 -> V_10 )
V_21 -= V_29 ;
V_30:
V_18 = F_9 ( V_21 , V_2 ) - V_21 ;
if ( V_18 & V_31 )
goto V_32;
F_10 ( & V_13 -> V_22 ) ;
V_15 = V_13 -> V_33 ;
F_11 () ;
V_13 -> V_33 = NULL ;
F_12 ( V_15 ) ;
F_13 ( V_15 ) ;
goto V_27;
V_25:
if ( V_11 == V_34 &&
F_9 ( 0 , V_2 ) < V_29 )
goto V_27;
V_19 = 0 ;
do {
V_19 ++ ;
if ( V_13 -> V_22 . V_17 == & V_2 -> V_10 )
break;
V_13 = F_8 ( V_13 -> V_22 . V_17 ,
struct V_12 , V_22 ) ;
} while ( V_13 -> V_23 & V_35 );
V_21 = V_19 * V_36 ;
if ( V_13 -> V_23 & V_35 )
V_21 -= V_29 ;
F_14 ( V_21 , V_2 ) ;
V_17 = V_2 -> V_10 . V_17 ;
for ( V_20 = V_19 ; V_20 > 0 ; V_20 -- ) {
V_13 = F_8 ( V_17 , struct V_12 , V_22 ) ;
V_17 = V_13 -> V_22 . V_17 ;
V_15 = V_13 -> V_33 ;
F_11 () ;
V_13 -> V_33 = NULL ;
F_12 ( V_15 ) ;
F_13 ( V_15 ) ;
}
V_2 -> V_10 . V_17 = V_17 ;
V_17 -> V_37 = & V_2 -> V_10 ;
V_27:
return V_2 ;
V_32:
if ( F_9 ( - V_21 , V_2 ) & V_31 )
goto V_27;
goto V_30;
}
static struct V_1 T_1 *
F_15 ( struct V_1 * V_2 ,
unsigned int V_23 , signed long V_21 )
{
struct V_12 V_13 ;
struct V_14 * V_15 = V_38 ;
signed long V_7 ;
F_16 ( V_15 , V_39 ) ;
F_17 ( & V_2 -> V_9 ) ;
V_13 . V_33 = V_15 ;
V_13 . V_23 = V_23 ;
F_18 ( V_15 ) ;
if ( F_19 ( & V_2 -> V_10 ) )
V_21 += V_29 ;
F_20 ( & V_13 . V_22 , & V_2 -> V_10 ) ;
V_7 = F_9 ( V_21 , V_2 ) ;
if ( V_7 == V_29 )
V_2 = F_7 ( V_2 , V_40 ) ;
else if ( V_7 > V_29 &&
V_21 == - V_28 )
V_2 = F_7 ( V_2 , V_26 ) ;
F_21 ( & V_2 -> V_9 ) ;
for (; ; ) {
if ( ! V_13 . V_33 )
break;
F_22 () ;
F_16 ( V_15 , V_39 ) ;
}
V_15 -> V_41 = V_42 ;
return V_2 ;
}
struct V_1 T_1 * F_23 ( struct V_1 * V_2 )
{
return F_15 ( V_2 , V_35 ,
- V_36 ) ;
}
struct V_1 T_1 * F_24 ( struct V_1 * V_2 )
{
return F_15 ( V_2 , V_24 ,
- V_28 ) ;
}
struct V_1 * F_25 ( struct V_1 * V_2 )
{
unsigned long V_23 ;
F_26 ( & V_2 -> V_9 , V_23 ) ;
if ( ! F_19 ( & V_2 -> V_10 ) )
V_2 = F_7 ( V_2 , V_34 ) ;
F_27 ( & V_2 -> V_9 , V_23 ) ;
return V_2 ;
}
struct V_1 * F_28 ( struct V_1 * V_2 )
{
unsigned long V_23 ;
F_26 ( & V_2 -> V_9 , V_23 ) ;
if ( ! F_19 ( & V_2 -> V_10 ) )
V_2 = F_7 ( V_2 , V_26 ) ;
F_27 ( & V_2 -> V_9 , V_23 ) ;
return V_2 ;
}
