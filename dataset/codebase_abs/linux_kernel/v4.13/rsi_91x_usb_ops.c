void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_4 -> V_8 ;
int V_9 ;
do {
F_2 ( & V_7 -> V_10 . V_11 , V_12 ) ;
if ( F_3 ( & V_7 -> V_10 . V_13 ) )
goto V_14;
F_4 ( & V_2 -> V_15 ) ;
V_9 = F_5 ( V_2 , 0 ) ;
if ( V_9 ) {
F_6 ( V_16 , L_1 , V_17 ) ;
F_7 ( & V_2 -> V_15 ) ;
return;
}
F_7 ( & V_2 -> V_15 ) ;
F_8 ( & V_7 -> V_10 . V_11 ) ;
if ( V_4 -> V_18 ( V_4 ) ) {
F_6 ( V_16 ,
L_2 , V_17 ) ;
return;
}
} while ( 1 );
V_14:
F_6 ( V_19 , L_3 , V_17 ) ;
F_9 ( & V_7 -> V_10 . V_20 , 0 ) ;
}
