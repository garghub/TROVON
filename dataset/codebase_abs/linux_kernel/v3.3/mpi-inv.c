int F_1 ( T_1 V_1 , const T_1 V_2 , const T_1 V_3 )
{
T_1 V_4 = NULL , V_5 = NULL ;
T_1 V_6 = NULL , V_7 = NULL , V_8 = NULL ;
T_1 V_9 = NULL , V_10 = NULL , V_11 = NULL ;
T_1 V_12 = NULL , V_13 = NULL , V_14 = NULL ;
unsigned V_15 ;
int V_16 ;
int V_17 = 0 ;
int V_18 = - V_19 ;
if ( F_2 ( & V_4 , V_2 ) < 0 )
goto V_20;
if ( F_2 ( & V_5 , V_3 ) < 0 )
goto V_20;
for ( V_15 = 0 ; ! F_3 ( V_4 , 0 ) && ! F_3 ( V_5 , 0 ) ; V_15 ++ ) {
if ( F_4 ( V_4 , V_4 , 1 ) < 0 )
goto V_20;
if ( F_4 ( V_5 , V_5 , 1 ) < 0 )
goto V_20;
}
V_17 = F_3 ( V_5 , 0 ) ;
V_6 = F_5 ( 1 ) ;
if ( ! V_6 )
goto V_20;
if ( ! V_17 ) {
V_7 = F_5 ( 0 ) ;
if ( ! V_7 )
goto V_20;
}
if ( F_2 ( & V_8 , V_4 ) < 0 )
goto V_20;
if ( F_2 ( & V_9 , V_5 ) < 0 )
goto V_20;
if ( ! V_17 ) {
V_10 = F_6 ( F_7 ( V_4 ) ) ;
if ( ! V_10 )
goto V_20;
if ( F_8 ( V_10 , V_6 , V_4 ) < 0 )
goto V_20;
}
if ( F_2 ( & V_11 , V_5 ) < 0 )
goto V_20;
if ( F_3 ( V_4 , 0 ) ) {
V_12 = F_5 ( 0 ) ;
if ( ! V_12 )
goto V_20;
if ( ! V_17 ) {
V_13 = F_5 ( 1 ) ;
if ( ! V_13 )
goto V_20;
V_13 -> V_16 = 1 ;
}
if ( F_2 ( & V_14 , V_5 ) < 0 )
goto V_20;
V_14 -> V_16 = ! V_14 -> V_16 ;
goto V_21;
} else {
V_12 = F_5 ( 1 ) ;
if ( ! V_12 )
goto V_20;
if ( ! V_17 ) {
V_13 = F_5 ( 0 ) ;
if ( ! V_13 )
goto V_20;
}
if ( F_2 ( & V_14 , V_4 ) < 0 )
goto V_20;
}
do {
do {
if ( ! V_17 ) {
if ( F_3 ( V_12 , 0 ) || F_3 ( V_13 , 0 ) ) {
if ( F_9 ( V_12 , V_12 , V_5 ) < 0 )
goto V_20;
if ( F_8 ( V_13 , V_13 , V_4 ) < 0 )
goto V_20;
}
if ( F_4 ( V_12 , V_12 , 1 ) < 0 )
goto V_20;
if ( F_4 ( V_13 , V_13 , 1 ) < 0 )
goto V_20;
if ( F_4 ( V_14 , V_14 , 1 ) < 0 )
goto V_20;
} else {
if ( F_3 ( V_12 , 0 ) )
if ( F_9 ( V_12 , V_12 , V_5 ) < 0 )
goto V_20;
if ( F_4 ( V_12 , V_12 , 1 ) < 0 )
goto V_20;
if ( F_4 ( V_14 , V_14 , 1 ) < 0 )
goto V_20;
}
V_21:
;
} while ( ! F_3 ( V_14 , 0 ) );
if ( ! V_14 -> V_16 ) {
if ( F_10 ( V_6 , V_12 ) < 0 )
goto V_20;
if ( ! V_17 )
if ( F_10 ( V_7 , V_13 ) < 0 )
goto V_20;
if ( F_10 ( V_8 , V_14 ) < 0 )
goto V_20;
} else {
if ( F_8 ( V_9 , V_5 , V_12 ) < 0 )
goto V_20;
V_16 = V_4 -> V_16 ;
V_4 -> V_16 = ! V_4 -> V_16 ;
if ( ! V_17 )
if ( F_8 ( V_10 , V_4 , V_13 ) < 0 )
goto V_20;
V_4 -> V_16 = V_16 ;
V_16 = V_14 -> V_16 ;
V_14 -> V_16 = ! V_14 -> V_16 ;
if ( F_10 ( V_11 , V_14 ) < 0 )
goto V_20;
V_14 -> V_16 = V_16 ;
}
if ( F_8 ( V_12 , V_6 , V_9 ) < 0 )
goto V_20;
if ( ! V_17 )
if ( F_8 ( V_13 , V_7 , V_10 ) < 0 )
goto V_20;
if ( F_8 ( V_14 , V_8 , V_11 ) < 0 )
goto V_20;
if ( V_12 -> V_16 ) {
if ( F_9 ( V_12 , V_12 , V_5 ) < 0 )
goto V_20;
if ( ! V_17 )
if ( F_8 ( V_13 , V_13 , V_4 ) < 0 )
goto V_20;
}
} while ( F_11 ( V_14 , 0 ) );
V_18 = F_10 ( V_1 , V_6 ) ;
V_20:
F_12 ( V_6 ) ;
F_12 ( V_9 ) ;
F_12 ( V_12 ) ;
if ( ! V_17 ) {
F_12 ( V_7 ) ;
F_12 ( V_10 ) ;
F_12 ( V_13 ) ;
}
F_12 ( V_8 ) ;
F_12 ( V_11 ) ;
F_12 ( V_14 ) ;
F_12 ( V_4 ) ;
F_12 ( V_5 ) ;
return V_18 ;
}
