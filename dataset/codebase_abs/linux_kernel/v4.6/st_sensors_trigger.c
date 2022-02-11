int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 , V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned long V_9 ;
V_8 -> V_10 = F_3 ( L_1 , V_2 -> V_11 ) ;
if ( V_8 -> V_10 == NULL ) {
F_4 ( & V_2 -> V_12 , L_2 ) ;
return - V_13 ;
}
V_6 = V_8 -> V_14 ( V_2 ) ;
V_9 = F_5 ( F_6 ( V_6 ) ) ;
if ( V_9 == V_15 ) {
if ( ! V_8 -> V_16 -> V_17 . V_18 ) {
F_4 ( & V_2 -> V_12 ,
L_3
L_4
L_5 ) ;
V_9 = V_19 ;
} else {
V_5 = F_7 ( V_2 ,
V_8 -> V_16 -> V_17 . V_18 ,
V_8 -> V_16 -> V_17 . V_20 , 1 ) ;
if ( V_5 < 0 )
goto V_21;
F_8 ( & V_2 -> V_12 ,
L_6 ) ;
}
} else if ( V_9 == V_19 ) {
F_8 ( & V_2 -> V_12 ,
L_7 ) ;
} else {
F_4 ( & V_2 -> V_12 ,
L_8
L_9
L_5 , V_9 ) ;
V_9 = V_19 ;
}
V_5 = F_9 ( V_6 ,
V_22 ,
NULL ,
V_9 ,
V_8 -> V_10 -> V_11 ,
V_8 -> V_10 ) ;
if ( V_5 ) {
F_4 ( & V_2 -> V_12 , L_10 ) ;
goto V_21;
}
F_10 ( V_8 -> V_10 , V_2 ) ;
V_8 -> V_10 -> V_23 = V_4 ;
V_8 -> V_10 -> V_12 . V_24 = V_8 -> V_12 ;
V_5 = F_11 ( V_8 -> V_10 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_12 , L_11 ) ;
goto V_25;
}
V_2 -> V_10 = F_12 ( V_8 -> V_10 ) ;
return 0 ;
V_25:
F_13 ( V_8 -> V_14 ( V_2 ) , V_8 -> V_10 ) ;
V_21:
V_21 ( V_8 -> V_10 ) ;
return V_5 ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_15 ( V_8 -> V_10 ) ;
F_13 ( V_8 -> V_14 ( V_2 ) , V_8 -> V_10 ) ;
V_21 ( V_8 -> V_10 ) ;
}
