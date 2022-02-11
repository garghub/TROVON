static inline bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( * V_2 -> V_4 ) ;
return F_3 ( V_3 ) && ! F_4 ( V_3 ) ;
}
static inline bool F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
return false ;
}
static bool F_7 ( struct V_1 * V_2 )
{
V_2 -> V_5 = F_8 ( V_2 -> V_4 , V_2 -> V_6 ) ;
if ( ! ( V_2 -> V_7 & V_8 ) ) {
if ( V_2 -> V_7 & V_9 ) {
if ( ! F_9 ( * V_2 -> V_5 ) )
return false ;
} else {
if ( ! F_10 ( * V_2 -> V_5 ) )
return false ;
}
}
V_2 -> V_10 = F_11 ( V_2 -> V_11 -> V_12 , V_2 -> V_4 ) ;
F_12 ( V_2 -> V_10 ) ;
return true ;
}
static bool F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 & V_9 ) {
#ifdef F_14
T_2 V_13 ;
if ( ! F_9 ( * V_2 -> V_5 ) )
return false ;
V_13 = F_15 ( * V_2 -> V_5 ) ;
if ( ! F_16 ( V_13 ) )
return false ;
if ( F_17 ( V_13 ) - V_2 -> V_14 >=
F_18 ( V_2 -> V_14 ) ) {
return false ;
}
if ( F_17 ( V_13 ) < V_2 -> V_14 )
return false ;
#else
F_19 ( 1 ) ;
#endif
} else {
if ( ! F_10 ( * V_2 -> V_5 ) )
return false ;
if ( F_20 ( * V_2 -> V_5 ) - V_2 -> V_14 >=
F_18 ( V_2 -> V_14 ) ) {
return false ;
}
if ( F_20 ( * V_2 -> V_5 ) < V_2 -> V_14 )
return false ;
}
return true ;
}
bool V_1 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_11 -> V_12 ;
struct V_14 * V_14 = V_2 -> V_14 ;
T_3 * V_17 ;
T_4 * V_18 ;
T_5 * V_19 ;
if ( V_2 -> V_4 && ! V_2 -> V_5 )
return F_5 ( V_2 ) ;
if ( V_2 -> V_5 )
goto V_20;
if ( F_21 ( F_22 ( V_2 -> V_14 ) ) ) {
V_2 -> V_5 = F_23 ( V_16 , V_2 -> V_6 ,
V_21 << F_24 ( V_14 ) ) ;
if ( ! V_2 -> V_5 )
return false ;
V_2 -> V_10 = F_25 ( F_26 ( V_14 ) , V_16 , V_2 -> V_5 ) ;
F_12 ( V_2 -> V_10 ) ;
if ( ! F_13 ( V_2 ) )
return F_5 ( V_2 ) ;
return true ;
}
V_22:
V_17 = F_27 ( V_16 , V_2 -> V_6 ) ;
if ( ! F_28 ( * V_17 ) )
return false ;
V_18 = F_29 ( V_17 , V_2 -> V_6 ) ;
if ( ! F_30 ( * V_18 ) )
return false ;
V_19 = F_31 ( V_18 , V_2 -> V_6 ) ;
if ( ! F_32 ( * V_19 ) )
return false ;
V_2 -> V_4 = F_33 ( V_19 , V_2 -> V_6 ) ;
if ( F_4 ( * V_2 -> V_4 ) ) {
V_2 -> V_10 = F_34 ( V_16 , V_2 -> V_4 ) ;
if ( ! F_3 ( * V_2 -> V_4 ) )
return F_5 ( V_2 ) ;
if ( F_35 ( F_4 ( * V_2 -> V_4 ) ) ) {
if ( V_2 -> V_7 & V_9 )
return F_5 ( V_2 ) ;
if ( F_36 ( * V_2 -> V_4 ) != V_14 )
return F_5 ( V_2 ) ;
return true ;
} else {
F_37 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
}
} else {
if ( ! F_1 ( V_2 ) )
return false ;
}
if ( ! F_7 ( V_2 ) )
goto V_20;
while ( 1 ) {
if ( F_13 ( V_2 ) )
return true ;
V_20:
if ( ! F_38 ( V_2 -> V_14 ) || F_22 ( V_2 -> V_14 ) )
return F_5 ( V_2 ) ;
do {
V_2 -> V_6 += V_21 ;
if ( V_2 -> V_6 >= V_2 -> V_11 -> V_23 ||
V_2 -> V_6 >=
F_39 ( V_2 -> V_14 , V_2 -> V_11 ) +
F_18 ( V_2 -> V_14 ) * V_21 )
return F_5 ( V_2 ) ;
if ( V_2 -> V_6 % V_24 == 0 ) {
F_40 ( V_2 -> V_5 ) ;
if ( V_2 -> V_10 ) {
F_37 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
}
goto V_22;
} else {
V_2 -> V_5 ++ ;
}
} while ( F_41 ( * V_2 -> V_5 ) );
if ( ! V_2 -> V_10 ) {
V_2 -> V_10 = F_11 ( V_16 , V_2 -> V_4 ) ;
F_12 ( V_2 -> V_10 ) ;
}
}
}
int F_42 ( struct V_14 * V_14 , struct V_25 * V_11 )
{
struct V_1 V_2 = {
. V_14 = V_14 ,
. V_11 = V_11 ,
. V_7 = V_8 ,
} ;
unsigned long V_26 , V_27 ;
V_26 = F_39 ( V_14 , V_11 ) ;
V_27 = V_26 + V_21 * ( F_18 ( V_14 ) - 1 ) ;
if ( F_21 ( V_27 < V_11 -> V_28 || V_26 >= V_11 -> V_23 ) )
return 0 ;
V_2 . V_6 = F_43 ( V_26 , V_11 -> V_28 ) ;
if ( ! V_1 ( & V_2 ) )
return 0 ;
F_6 ( & V_2 ) ;
return 1 ;
}
