static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
if ( ! F_4 ( V_4 , & V_2 -> V_5 ) ) {
F_5 ( V_4 , & V_2 -> V_5 ) ;
F_6 ( & V_2 -> V_3 ) ;
}
}
void F_7 ( struct V_1 * V_2 )
{
if ( F_4 ( V_4 , & V_2 -> V_5 ) ) {
F_1 ( V_2 ) ;
F_8 ( V_4 , & V_2 -> V_5 ) ;
F_9 () ;
}
}
static int F_10 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < 512 ; V_6 ++ ) {
if ( ! F_4 ( V_4 , & V_2 -> V_5 ) )
return 1 ;
if ( F_11 () )
break;
F_12 () ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_6 ;
if ( F_10 ( V_2 ) ) {
F_1 ( V_2 ) ;
if ( ! F_4 ( V_4 , & V_2 -> V_5 ) )
return 1 ;
F_6 ( & V_2 -> V_3 ) ;
}
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
F_12 () ;
if ( ! F_10 ( V_2 ) )
break;
F_1 ( V_2 ) ;
if ( ! F_4 ( V_4 , & V_2 -> V_5 ) )
return 1 ;
F_6 ( & V_2 -> V_3 ) ;
}
return 0 ;
}
static int F_14 ( T_1 * V_7 , unsigned V_8 ,
int V_9 , void * V_10 )
{
F_15 ( V_7 , V_8 , V_9 , V_10 ) ;
return 1 ;
}
int F_16 ( struct V_1 * V_2 )
{
F_17 ( V_7 ) ;
V_7 . V_11 = F_14 ;
if ( ! F_10 ( V_2 ) )
goto V_12;
while( 1 ) {
F_1 ( V_2 ) ;
if ( ! F_4 ( V_4 , & V_2 -> V_5 ) )
return 0 ;
F_6 ( & V_2 -> V_3 ) ;
F_12 () ;
if ( F_10 ( V_2 ) )
continue;
V_12:
F_18 ( & V_2 -> V_13 , & V_7 ,
V_14 ) ;
if ( F_4 ( V_4 , & V_2 -> V_5 ) )
F_19 () ;
F_20 ( & V_2 -> V_13 , & V_7 ) ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
if ( F_22 ( V_4 , & V_2 -> V_5 ) )
F_9 () ;
else
F_6 ( & V_2 -> V_3 ) ;
if ( F_23 ( & V_2 -> V_13 ) )
F_24 ( & V_2 -> V_13 ) ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
if ( ! F_4 ( V_4 , & V_2 -> V_5 ) )
F_26 ( & V_2 -> V_3 ) ;
}
