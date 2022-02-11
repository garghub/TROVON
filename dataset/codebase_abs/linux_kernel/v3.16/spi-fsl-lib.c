struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_5 , struct V_6 ,
V_5 ) ;
F_4 ( & V_6 -> V_7 ) ;
while ( ! F_5 ( & V_6 -> V_8 ) ) {
struct V_9 * V_10 = F_2 ( V_6 -> V_8 . V_11 ,
struct V_9 , V_8 ) ;
F_6 ( & V_10 -> V_8 ) ;
F_7 ( & V_6 -> V_7 ) ;
if ( V_6 -> V_12 )
V_6 -> V_12 ( V_10 ) ;
F_4 ( & V_6 -> V_7 ) ;
}
F_7 ( & V_6 -> V_7 ) ;
}
int F_8 ( struct V_13 * V_14 ,
struct V_9 * V_10 )
{
struct V_6 * V_6 = F_9 ( V_14 -> V_15 ) ;
unsigned long V_16 ;
V_10 -> V_17 = 0 ;
V_10 -> V_18 = - V_19 ;
F_10 ( & V_6 -> V_7 , V_16 ) ;
F_11 ( & V_10 -> V_8 , & V_6 -> V_8 ) ;
F_12 ( V_6 -> V_20 , & V_6 -> V_5 ) ;
F_13 ( & V_6 -> V_7 , V_16 ) ;
return 0 ;
}
const char * F_14 ( unsigned int V_16 )
{
if ( V_16 & V_21 ) {
return L_1 ;
} else if ( V_16 & V_22 ) {
if ( V_16 & V_23 )
return L_2 ;
else if ( V_16 & V_24 )
return L_3 ;
else
return L_4 ;
}
return L_5 ;
}
int F_15 ( struct V_25 * V_26 , struct V_27 * V_28 ,
unsigned int V_29 )
{
struct V_2 * V_3 = F_16 ( V_26 ) ;
struct V_30 * V_15 ;
struct V_6 * V_6 ;
int V_31 = 0 ;
V_15 = F_17 ( V_26 ) ;
V_15 -> V_32 = V_33 | V_34 | V_35
| V_36 | V_37 ;
V_15 -> V_38 = F_8 ;
V_15 -> V_26 . V_39 = V_26 -> V_39 ;
V_6 = F_9 ( V_15 ) ;
V_6 -> V_26 = V_26 ;
V_6 -> V_40 = V_41 ;
V_6 -> V_42 = V_43 ;
V_6 -> V_16 = V_3 -> V_16 ;
V_6 -> V_44 = V_3 -> V_45 ;
V_6 -> V_29 = V_29 ;
V_6 -> V_46 = 0 ;
V_6 -> V_47 = 0 ;
F_18 ( & V_6 -> V_48 ) ;
V_15 -> V_49 = V_3 -> V_49 ;
V_15 -> V_50 = V_3 -> V_51 ;
F_19 ( & V_6 -> V_7 ) ;
F_18 ( & V_6 -> V_48 ) ;
F_20 ( & V_6 -> V_5 , F_3 ) ;
F_21 ( & V_6 -> V_8 ) ;
V_6 -> V_20 = F_22 (
F_23 ( V_15 -> V_26 . V_52 ) ) ;
if ( V_6 -> V_20 == NULL ) {
V_31 = - V_53 ;
goto V_54;
}
return 0 ;
V_54:
return V_31 ;
}
int F_24 ( struct V_25 * V_26 )
{
struct V_6 * V_6 ;
struct V_30 * V_15 ;
V_15 = F_17 ( V_26 ) ;
V_6 = F_9 ( V_15 ) ;
F_25 ( V_6 -> V_20 ) ;
F_26 ( V_6 -> V_20 ) ;
F_27 ( V_15 ) ;
F_28 ( V_6 -> V_29 , V_6 ) ;
if ( V_6 -> V_55 )
V_6 -> V_55 ( V_6 ) ;
return 0 ;
}
int F_29 ( struct V_56 * V_57 )
{
struct V_25 * V_26 = & V_57 -> V_26 ;
struct V_58 * V_59 = V_57 -> V_26 . V_39 ;
struct V_1 * V_60 ;
struct V_2 * V_3 ;
const void * V_61 ;
int V_31 = - V_62 ;
V_60 = F_30 ( & V_57 -> V_26 , sizeof( * V_60 ) , V_63 ) ;
if ( ! V_60 )
return - V_62 ;
V_3 = & V_60 -> V_3 ;
V_26 -> V_64 = V_3 ;
V_3 -> V_49 = - 1 ;
#ifdef F_31
V_3 -> V_45 = F_32 () ;
if ( V_3 -> V_45 == - 1 ) {
V_3 -> V_45 = F_33 () ;
if ( V_3 -> V_45 == - 1 )
return - V_65 ;
}
#else
V_31 = F_34 ( V_59 , L_6 , & V_3 -> V_45 ) ;
if ( V_31 )
return V_31 ;
#endif
V_61 = F_35 ( V_59 , L_7 , NULL ) ;
if ( V_61 && ! strcmp ( V_61 , L_8 ) )
V_3 -> V_16 = V_21 ;
else if ( V_61 && ! strcmp ( V_61 , L_9 ) )
V_3 -> V_16 = V_22 | V_23 ;
else if ( F_36 ( V_59 , L_10 ) )
V_3 -> V_16 = V_22 | V_24 ;
else if ( F_36 ( V_59 , L_11 ) )
V_3 -> V_16 = V_22 | V_66 ;
return 0 ;
}
