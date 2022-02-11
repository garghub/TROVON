struct V_1 * F_1 ( const char * V_2 , T_1 V_3 )
{
struct V_1 * V_4 , * V_5 ;
struct V_6 * * V_7 , * V_8 ;
int V_9 ;
V_5 = NULL ;
F_2 ( & V_10 ) ;
V_7 = & V_11 . V_6 ;
while ( * V_7 ) {
V_5 = F_3 ( * V_7 , struct V_1 , V_12 ) ;
V_9 = F_4 ( V_5 , V_2 , V_3 ) ;
if ( V_9 > 0 )
V_7 = & ( * V_7 ) -> V_13 ;
else if ( V_9 < 0 )
V_7 = & ( * V_7 ) -> V_14 ;
else
break;
V_5 = NULL ;
}
if ( V_5 && ! F_5 ( & V_5 -> V_15 ) ) {
F_6 ( & V_5 -> V_12 , & V_11 ) ;
F_7 ( & V_5 -> V_12 ) ;
V_5 = NULL ;
}
F_8 ( & V_10 ) ;
if ( V_5 )
return V_5 ;
V_4 = F_9 ( sizeof( * V_4 ) + V_3 + 1 , V_16 ) ;
if ( ! V_4 )
return NULL ;
F_10 ( & V_4 -> V_15 ) ;
V_4 -> V_3 = V_3 ;
memcpy ( V_4 -> V_2 , V_2 , V_3 ) ;
V_4 -> V_2 [ V_3 ] = 0 ;
V_17:
V_5 = NULL ;
V_8 = NULL ;
V_7 = & V_11 . V_6 ;
F_2 ( & V_10 ) ;
while ( * V_7 ) {
V_8 = * V_7 ;
V_5 = F_3 ( * V_7 , struct V_1 , V_12 ) ;
V_9 = F_4 ( V_5 , V_2 , V_3 ) ;
if ( V_9 > 0 )
V_7 = & ( * V_7 ) -> V_13 ;
else if ( V_9 < 0 )
V_7 = & ( * V_7 ) -> V_14 ;
else
break;
V_5 = NULL ;
}
V_9 = 0 ;
if ( ! V_5 ) {
F_11 ( & V_4 -> V_12 , V_8 , V_7 ) ;
F_12 ( & V_4 -> V_12 , & V_11 ) ;
} else if ( ! F_5 ( & V_5 -> V_15 ) ) {
F_6 ( & V_5 -> V_12 , & V_11 ) ;
F_7 ( & V_5 -> V_12 ) ;
V_9 = - V_18 ;
}
F_8 ( & V_10 ) ;
if ( V_9 == - V_18 )
goto V_17;
if ( V_5 ) {
F_13 ( V_4 ) ;
V_4 = V_5 ;
}
return V_4 ;
}
void F_14 ( struct V_15 * V_19 )
{
struct V_1 * V_4 = F_15 ( V_19 , struct V_1 , V_15 ) ;
F_2 ( & V_10 ) ;
if ( ! F_16 ( & V_4 -> V_12 ) ) {
F_6 ( & V_4 -> V_12 , & V_11 ) ;
F_7 ( & V_4 -> V_12 ) ;
}
F_8 ( & V_10 ) ;
F_17 ( V_4 , V_20 ) ;
}
bool F_18 ( void )
{
return F_19 ( & V_11 ) ;
}
