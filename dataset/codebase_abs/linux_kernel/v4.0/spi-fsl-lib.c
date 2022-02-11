struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
const char * F_3 ( unsigned int V_4 )
{
if ( V_4 & V_5 ) {
return L_1 ;
} else if ( V_4 & V_6 ) {
if ( V_4 & V_7 )
return L_2 ;
else if ( V_4 & V_8 )
return L_3 ;
else
return L_4 ;
}
return L_5 ;
}
void F_4 ( struct V_9 * V_10 , struct V_11 * V_12 ,
unsigned int V_13 )
{
struct V_2 * V_3 = F_5 ( V_10 ) ;
struct V_14 * V_15 ;
struct V_16 * V_16 ;
V_15 = F_6 ( V_10 ) ;
V_15 -> V_17 = V_18 | V_19 | V_20
| V_21 | V_22 ;
V_15 -> V_10 . V_23 = V_10 -> V_23 ;
V_16 = F_7 ( V_15 ) ;
V_16 -> V_10 = V_10 ;
V_16 -> V_24 = V_25 ;
V_16 -> V_26 = V_27 ;
V_16 -> V_4 = V_3 -> V_4 ;
V_16 -> V_28 = V_3 -> V_29 ;
V_16 -> V_13 = V_13 ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = 0 ;
V_15 -> V_32 = V_3 -> V_32 ;
V_15 -> V_33 = V_3 -> V_34 ;
F_8 ( & V_16 -> V_35 ) ;
}
int F_9 ( struct V_9 * V_10 )
{
struct V_16 * V_16 ;
struct V_14 * V_15 ;
V_15 = F_6 ( V_10 ) ;
V_16 = F_7 ( V_15 ) ;
F_10 ( V_15 ) ;
F_11 ( V_16 -> V_13 , V_16 ) ;
if ( V_16 -> V_36 )
V_16 -> V_36 ( V_16 ) ;
return 0 ;
}
int F_12 ( struct V_37 * V_38 )
{
struct V_9 * V_10 = & V_38 -> V_10 ;
struct V_39 * V_40 = V_38 -> V_10 . V_23 ;
struct V_1 * V_41 ;
struct V_2 * V_3 ;
const void * V_42 ;
int V_43 = - V_44 ;
V_41 = F_13 ( & V_38 -> V_10 , sizeof( * V_41 ) , V_45 ) ;
if ( ! V_41 )
return V_43 ;
V_3 = & V_41 -> V_3 ;
V_10 -> V_46 = V_3 ;
V_3 -> V_32 = - 1 ;
#ifdef F_14
V_3 -> V_29 = F_15 () ;
if ( V_3 -> V_29 == - 1 ) {
V_3 -> V_29 = F_16 () ;
if ( V_3 -> V_29 == - 1 )
return - V_47 ;
}
#else
V_43 = F_17 ( V_40 , L_6 , & V_3 -> V_29 ) ;
if ( V_43 )
return V_43 ;
#endif
V_42 = F_18 ( V_40 , L_7 , NULL ) ;
if ( V_42 && ! strcmp ( V_42 , L_8 ) )
V_3 -> V_4 = V_5 ;
else if ( V_42 && ! strcmp ( V_42 , L_9 ) )
V_3 -> V_4 = V_6 | V_7 ;
else if ( F_19 ( V_40 , L_10 ) )
V_3 -> V_4 = V_6 | V_8 ;
else if ( F_19 ( V_40 , L_11 ) )
V_3 -> V_4 = V_6 | V_48 ;
return 0 ;
}
