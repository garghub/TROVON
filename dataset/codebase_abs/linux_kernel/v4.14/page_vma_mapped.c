static inline bool F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
return false ;
}
static bool F_3 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_4 ( V_2 -> V_4 , V_2 -> V_5 ) ;
if ( ! ( V_2 -> V_6 & V_7 ) ) {
if ( V_2 -> V_6 & V_8 ) {
if ( ! F_5 ( * V_2 -> V_3 ) )
return false ;
} else {
if ( ! F_6 ( * V_2 -> V_3 ) )
return false ;
}
}
V_2 -> V_9 = F_7 ( V_2 -> V_10 -> V_11 , V_2 -> V_4 ) ;
F_8 ( V_2 -> V_9 ) ;
return true ;
}
static bool F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 & V_8 ) {
#ifdef F_10
T_1 V_12 ;
if ( ! F_5 ( * V_2 -> V_3 ) )
return false ;
V_12 = F_11 ( * V_2 -> V_3 ) ;
if ( ! F_12 ( V_12 ) )
return false ;
if ( F_13 ( V_12 ) - V_2 -> V_13 >=
F_14 ( V_2 -> V_13 ) ) {
return false ;
}
if ( F_13 ( V_12 ) < V_2 -> V_13 )
return false ;
#else
F_15 ( 1 ) ;
#endif
} else {
if ( F_5 ( * V_2 -> V_3 ) ) {
T_1 V_12 ;
V_12 = F_11 ( * V_2 -> V_3 ) ;
if ( F_16 ( V_12 ) &&
F_17 ( V_12 ) == V_2 -> V_13 )
return true ;
}
if ( ! F_6 ( * V_2 -> V_3 ) )
return false ;
if ( F_18 ( * V_2 -> V_3 ) - V_2 -> V_13 >=
F_14 ( V_2 -> V_13 ) ) {
return false ;
}
if ( F_18 ( * V_2 -> V_3 ) < V_2 -> V_13 )
return false ;
}
return true ;
}
bool V_1 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_10 -> V_11 ;
struct V_13 * V_13 = V_2 -> V_13 ;
T_2 * V_16 ;
T_3 * V_17 ;
T_4 * V_18 ;
T_5 V_19 ;
if ( V_2 -> V_4 && ! V_2 -> V_3 )
return F_1 ( V_2 ) ;
if ( V_2 -> V_3 )
goto V_20;
if ( F_19 ( F_20 ( V_2 -> V_13 ) ) ) {
V_2 -> V_3 = F_21 ( V_15 , V_2 -> V_5 ,
V_21 << F_22 ( V_13 ) ) ;
if ( ! V_2 -> V_3 )
return false ;
V_2 -> V_9 = F_23 ( F_24 ( V_13 ) , V_15 , V_2 -> V_3 ) ;
F_8 ( V_2 -> V_9 ) ;
if ( ! F_9 ( V_2 ) )
return F_1 ( V_2 ) ;
return true ;
}
V_22:
V_16 = F_25 ( V_15 , V_2 -> V_5 ) ;
if ( ! F_26 ( * V_16 ) )
return false ;
V_17 = F_27 ( V_16 , V_2 -> V_5 ) ;
if ( ! F_28 ( * V_17 ) )
return false ;
V_18 = F_29 ( V_17 , V_2 -> V_5 ) ;
if ( ! F_30 ( * V_18 ) )
return false ;
V_2 -> V_4 = F_31 ( V_18 , V_2 -> V_5 ) ;
V_19 = F_32 ( * V_2 -> V_4 ) ;
if ( F_33 ( V_19 ) || F_34 ( V_19 ) ) {
V_2 -> V_9 = F_35 ( V_15 , V_2 -> V_4 ) ;
if ( F_36 ( F_33 ( * V_2 -> V_4 ) ) ) {
if ( V_2 -> V_6 & V_8 )
return F_1 ( V_2 ) ;
if ( F_37 ( * V_2 -> V_4 ) != V_13 )
return F_1 ( V_2 ) ;
return true ;
} else if ( ! F_38 ( * V_2 -> V_4 ) ) {
if ( F_39 () ) {
if ( ! ( V_2 -> V_6 & V_8 ) )
return F_1 ( V_2 ) ;
if ( F_12 ( F_40 ( * V_2 -> V_4 ) ) ) {
T_1 V_12 = F_40 ( * V_2 -> V_4 ) ;
if ( F_13 ( V_12 ) != V_13 )
return F_1 ( V_2 ) ;
return true ;
}
}
return F_1 ( V_2 ) ;
} else {
F_41 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
} else if ( ! F_38 ( V_19 ) ) {
return false ;
}
if ( ! F_3 ( V_2 ) )
goto V_20;
while ( 1 ) {
if ( F_9 ( V_2 ) )
return true ;
V_20:
if ( ! F_42 ( V_2 -> V_13 ) || F_20 ( V_2 -> V_13 ) )
return F_1 ( V_2 ) ;
do {
V_2 -> V_5 += V_21 ;
if ( V_2 -> V_5 >= V_2 -> V_10 -> V_23 ||
V_2 -> V_5 >=
F_43 ( V_2 -> V_13 , V_2 -> V_10 ) +
F_14 ( V_2 -> V_13 ) * V_21 )
return F_1 ( V_2 ) ;
if ( V_2 -> V_5 % V_24 == 0 ) {
F_44 ( V_2 -> V_3 ) ;
if ( V_2 -> V_9 ) {
F_41 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
goto V_22;
} else {
V_2 -> V_3 ++ ;
}
} while ( F_45 ( * V_2 -> V_3 ) );
if ( ! V_2 -> V_9 ) {
V_2 -> V_9 = F_7 ( V_15 , V_2 -> V_4 ) ;
F_8 ( V_2 -> V_9 ) ;
}
}
}
int F_46 ( struct V_13 * V_13 , struct V_25 * V_10 )
{
struct V_1 V_2 = {
. V_13 = V_13 ,
. V_10 = V_10 ,
. V_6 = V_7 ,
} ;
unsigned long V_26 , V_27 ;
V_26 = F_43 ( V_13 , V_10 ) ;
V_27 = V_26 + V_21 * ( F_14 ( V_13 ) - 1 ) ;
if ( F_19 ( V_27 < V_10 -> V_28 || V_26 >= V_10 -> V_23 ) )
return 0 ;
V_2 . V_5 = F_47 ( V_26 , V_10 -> V_28 ) ;
if ( ! V_1 ( & V_2 ) )
return 0 ;
F_2 ( & V_2 ) ;
return 1 ;
}
