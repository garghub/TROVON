struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
void F_3 ( struct V_4 * V_5 )
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
void F_14 ( struct V_13 * V_14 )
{
F_15 ( V_14 -> V_21 ) ;
}
const char * F_16 ( unsigned int V_16 )
{
if ( V_16 & V_22 ) {
return L_1 ;
} else if ( V_16 & V_23 ) {
if ( V_16 & V_24 )
return L_2 ;
else if ( V_16 & V_25 )
return L_3 ;
else
return L_4 ;
}
return L_5 ;
}
int F_17 ( struct V_26 * V_27 , struct V_28 * V_29 ,
unsigned int V_30 )
{
struct V_2 * V_3 = V_27 -> V_31 ;
struct V_32 * V_15 ;
struct V_6 * V_6 ;
int V_33 = 0 ;
V_15 = F_18 ( V_27 ) ;
V_15 -> V_34 = V_35 | V_36 | V_37
| V_38 | V_39 ;
V_15 -> V_40 = F_8 ;
V_15 -> V_41 = F_14 ;
V_15 -> V_27 . V_42 = V_27 -> V_42 ;
V_6 = F_9 ( V_15 ) ;
V_6 -> V_27 = V_27 ;
V_6 -> V_43 = V_44 ;
V_6 -> V_45 = V_46 ;
V_6 -> V_16 = V_3 -> V_16 ;
V_6 -> V_47 = V_3 -> V_48 ;
V_6 -> V_30 = V_30 ;
V_6 -> V_49 = 0 ;
V_6 -> V_50 = 0 ;
F_19 ( & V_6 -> V_51 ) ;
V_15 -> V_52 = V_3 -> V_52 ;
V_15 -> V_53 = V_3 -> V_54 ;
F_20 ( & V_6 -> V_7 ) ;
F_19 ( & V_6 -> V_51 ) ;
F_21 ( & V_6 -> V_5 , F_3 ) ;
F_22 ( & V_6 -> V_8 ) ;
V_6 -> V_20 = F_23 (
F_24 ( V_15 -> V_27 . V_55 ) ) ;
if ( V_6 -> V_20 == NULL ) {
V_33 = - V_56 ;
goto V_57;
}
return 0 ;
V_57:
return V_33 ;
}
int F_25 ( struct V_26 * V_27 )
{
struct V_6 * V_6 ;
struct V_32 * V_15 ;
V_15 = F_18 ( V_27 ) ;
V_6 = F_9 ( V_15 ) ;
F_26 ( V_6 -> V_20 ) ;
F_27 ( V_6 -> V_20 ) ;
F_28 ( V_15 ) ;
F_29 ( V_6 -> V_30 , V_6 ) ;
if ( V_6 -> V_58 )
V_6 -> V_58 ( V_6 ) ;
return 0 ;
}
int F_30 ( struct V_59 * V_60 )
{
struct V_26 * V_27 = & V_60 -> V_27 ;
struct V_61 * V_62 = V_60 -> V_27 . V_42 ;
struct V_1 * V_63 ;
struct V_2 * V_3 ;
const void * V_64 ;
int V_33 = - V_65 ;
V_63 = F_31 ( sizeof( * V_63 ) , V_66 ) ;
if ( ! V_63 )
return - V_65 ;
V_3 = & V_63 -> V_3 ;
V_27 -> V_31 = V_3 ;
V_3 -> V_52 = - 1 ;
V_3 -> V_48 = F_32 () ;
if ( V_3 -> V_48 == - 1 ) {
V_3 -> V_48 = F_33 () ;
if ( V_3 -> V_48 == - 1 ) {
V_33 = - V_67 ;
goto V_57;
}
}
V_64 = F_34 ( V_62 , L_6 , NULL ) ;
if ( V_64 && ! strcmp ( V_64 , L_7 ) )
V_3 -> V_16 = V_22 ;
else if ( V_64 && ! strcmp ( V_64 , L_8 ) )
V_3 -> V_16 = V_23 | V_24 ;
else if ( F_35 ( V_62 , L_9 ) )
V_3 -> V_16 = V_23 | V_25 ;
else if ( F_35 ( V_62 , L_10 ) )
V_3 -> V_16 = V_23 | V_68 ;
return 0 ;
V_57:
F_15 ( V_63 ) ;
return V_33 ;
}
