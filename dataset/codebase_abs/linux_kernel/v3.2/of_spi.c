void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
const T_1 * V_7 ;
int V_8 ;
int V_9 ;
if ( ! V_2 -> V_10 . V_11 )
return;
F_2 (master->dev.of_node, nc) {
V_4 = F_3 ( V_2 ) ;
if ( ! V_4 ) {
F_4 ( & V_2 -> V_10 , L_1 ,
V_6 -> V_12 ) ;
F_5 ( V_4 ) ;
continue;
}
if ( F_6 ( V_6 , V_4 -> V_13 ,
sizeof( V_4 -> V_13 ) ) < 0 ) {
F_4 ( & V_2 -> V_10 , L_2 ,
V_6 -> V_12 ) ;
F_5 ( V_4 ) ;
continue;
}
V_7 = F_7 ( V_6 , L_3 , & V_9 ) ;
if ( ! V_7 || V_9 < sizeof( * V_7 ) ) {
F_4 ( & V_2 -> V_10 , L_4 ,
V_6 -> V_12 ) ;
F_5 ( V_4 ) ;
continue;
}
V_4 -> V_14 = F_8 ( V_7 ) ;
if ( F_9 ( V_6 , L_5 , NULL ) )
V_4 -> V_15 |= V_16 ;
if ( F_9 ( V_6 , L_6 , NULL ) )
V_4 -> V_15 |= V_17 ;
if ( F_9 ( V_6 , L_7 , NULL ) )
V_4 -> V_15 |= V_18 ;
V_7 = F_7 ( V_6 , L_8 , & V_9 ) ;
if ( ! V_7 || V_9 < sizeof( * V_7 ) ) {
F_4 ( & V_2 -> V_10 , L_9 ,
V_6 -> V_12 ) ;
F_5 ( V_4 ) ;
continue;
}
V_4 -> V_19 = F_8 ( V_7 ) ;
V_4 -> V_20 = F_10 ( V_6 , 0 ) ;
F_11 ( V_6 ) ;
V_4 -> V_10 . V_11 = V_6 ;
F_12 ( V_4 -> V_13 ) ;
V_8 = F_13 ( V_4 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_10 , L_10 ,
V_6 -> V_12 ) ;
F_5 ( V_4 ) ;
}
}
}
