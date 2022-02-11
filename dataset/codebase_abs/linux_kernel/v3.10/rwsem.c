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
F_7 ( struct V_1 * V_2 , enum V_11 V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
long V_19 , V_20 , V_21 , V_22 ;
V_14 = F_8 ( V_2 -> V_10 . V_18 , struct V_13 , V_23 ) ;
if ( V_14 -> type == V_24 ) {
if ( V_12 == V_25 )
F_9 ( V_14 -> V_26 ) ;
goto V_27;
}
V_22 = 0 ;
if ( V_12 != V_28 ) {
V_22 = V_29 ;
V_30:
V_19 = F_10 ( V_22 , V_2 ) - V_22 ;
if ( F_11 ( V_19 < V_31 ) ) {
if ( F_10 ( - V_22 , V_2 ) &
V_32 )
goto V_27;
goto V_30;
}
}
V_20 = 0 ;
do {
V_20 ++ ;
if ( V_14 -> V_23 . V_18 == & V_2 -> V_10 )
break;
V_14 = F_8 ( V_14 -> V_23 . V_18 ,
struct V_13 , V_23 ) ;
} while ( V_14 -> type != V_24 );
V_22 = V_20 * V_29 - V_22 ;
if ( V_14 -> type != V_24 )
V_22 -= V_31 ;
if ( V_22 )
F_12 ( V_22 , V_2 ) ;
V_18 = V_2 -> V_10 . V_18 ;
V_21 = V_20 ;
do {
V_14 = F_8 ( V_18 , struct V_13 , V_23 ) ;
V_18 = V_14 -> V_23 . V_18 ;
V_16 = V_14 -> V_26 ;
F_13 () ;
V_14 -> V_26 = NULL ;
F_9 ( V_16 ) ;
F_14 ( V_16 ) ;
} while ( -- V_21 );
V_2 -> V_10 . V_18 = V_18 ;
V_18 -> V_33 = & V_2 -> V_10 ;
V_27:
return V_2 ;
}
struct V_1 T_1 * F_15 ( struct V_1 * V_2 )
{
long V_7 , V_22 = - V_29 ;
struct V_13 V_14 ;
struct V_15 * V_16 = V_34 ;
V_14 . V_26 = V_16 ;
V_14 . type = V_35 ;
F_16 ( V_16 ) ;
F_17 ( & V_2 -> V_9 ) ;
if ( F_18 ( & V_2 -> V_10 ) )
V_22 += V_31 ;
F_19 ( & V_14 . V_23 , & V_2 -> V_10 ) ;
V_7 = F_10 ( V_22 , V_2 ) ;
if ( V_7 == V_31 ||
( V_7 > V_31 &&
V_22 != - V_29 ) )
V_2 = F_7 ( V_2 , V_25 ) ;
F_20 ( & V_2 -> V_9 ) ;
while ( true ) {
F_21 ( V_16 , V_36 ) ;
if ( ! V_14 . V_26 )
break;
F_22 () ;
}
V_16 -> V_37 = V_38 ;
return V_2 ;
}
struct V_1 T_1 * F_23 ( struct V_1 * V_2 )
{
long V_7 , V_22 = - V_39 ;
struct V_13 V_14 ;
struct V_15 * V_16 = V_34 ;
V_14 . V_26 = V_16 ;
V_14 . type = V_24 ;
F_17 ( & V_2 -> V_9 ) ;
if ( F_18 ( & V_2 -> V_10 ) )
V_22 += V_31 ;
F_19 ( & V_14 . V_23 , & V_2 -> V_10 ) ;
V_7 = F_10 ( V_22 , V_2 ) ;
if ( V_7 > V_31 &&
V_22 == - V_39 )
V_2 = F_7 ( V_2 , V_40 ) ;
F_21 ( V_16 , V_36 ) ;
while ( true ) {
if ( ! ( V_7 & V_32 ) ) {
V_7 = V_39 ;
if ( ! F_24 ( & V_2 -> V_10 ) )
V_7 += V_31 ;
if ( V_2 -> V_7 == V_31 &&
F_25 ( & V_2 -> V_7 , V_31 , V_7 ) ==
V_31 )
break;
}
F_20 ( & V_2 -> V_9 ) ;
do {
F_22 () ;
F_21 ( V_16 , V_36 ) ;
} while ( ( V_7 = V_2 -> V_7 ) & V_32 );
F_17 ( & V_2 -> V_9 ) ;
}
F_26 ( & V_14 . V_23 ) ;
F_20 ( & V_2 -> V_9 ) ;
V_16 -> V_37 = V_38 ;
return V_2 ;
}
struct V_1 * F_27 ( struct V_1 * V_2 )
{
unsigned long V_41 ;
F_28 ( & V_2 -> V_9 , V_41 ) ;
if ( ! F_18 ( & V_2 -> V_10 ) )
V_2 = F_7 ( V_2 , V_25 ) ;
F_29 ( & V_2 -> V_9 , V_41 ) ;
return V_2 ;
}
struct V_1 * F_30 ( struct V_1 * V_2 )
{
unsigned long V_41 ;
F_28 ( & V_2 -> V_9 , V_41 ) ;
if ( ! F_18 ( & V_2 -> V_10 ) )
V_2 = F_7 ( V_2 , V_28 ) ;
F_29 ( & V_2 -> V_9 , V_41 ) ;
return V_2 ;
}
